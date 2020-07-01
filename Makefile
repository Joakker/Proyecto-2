CXX			:= g++
TARGET		:= prog

SRCDIR		:= src
OBJDIR		:= obj
BINDIR		:= bin

SRCEXT		:= cpp
OBJEXT		:= o
DEPEXT 		:= d

CXXFLAGS 	:= -Wall -O0 -g

LIBS 		:= 
INCL		:=
INCD		:=


SOURCES 	:= ${shell find $(SRCDIR) -type f -name '*.$(SRCEXT)'}
OBJECTS 	:= ${patsubst $(SRCDIR)/%, $(OBJDIR)/%, $(SOURCES:.$(SRCEXT)=.$(OBJEXT))}

all: resources $(TARGET)

resources: directories

remake: cleaner all

clean:
	@$(RM) -rf $(OBJDIR)

cleaner: clean
	@$(RM) -rf $(BINDIR)

directories:
	@mkdir -p $(BINDIR)
	@mkdir -p $(OBJDIR)

-include $(OBJECTS:.$(OBJEXT)=.$(DEPEXT))

$(TARGET): $(OBJECTS)
	$(CXX) -o $(BINDIR)/$@ $^ $(LIBS)

$(OBJDIR)/%.$(OBJEXT): $(SRCDIR)/%.$(SRCEXT)
	@mkdir -p ${dir $@}
	$(CXX) $(CXXFLAGS) $(INCL) -c -o $@ $<
	@$(CXX) $(CXXFLAGS) $(INCD) -MM $(SRCDIR)/$*.$(SRCEXT) > $(OBJDIR)/$*.$(DEPEXT)
	@cp -f $(OBJDIR)/$*.$(DEPEXT) $(OBJDIR)/$*.$(DEPEXT).tmp
	@sed -e 's|.*:|$(OBJDIR)/$*.$(OBJEXT):|' < $(OBJDIR)/$*.$(DEPEXT).tmp > $(OBJDIR)/$*.$(DEPEXT)
	@sed -e 's/.*://' -e 's/\\$$//' < $(OBJDIR)/$*.$(DEPEXT).tmp | fmt -1 | sed -e 's/^*//' -e 's/$$/:/' >> $(OBJDIR)/$*.$(OBJEXT)
	@rm -f $(OBJDIR)/$*.$(DEPEXT).tmp

.PHONY: all