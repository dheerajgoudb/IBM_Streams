# NOTE: This makefile is designed to be run from one level up in the directory
# hierarchy compared to where it resides. For instance, if this makefile is
# located at 'output/build/Makefile', then it can be launched as:
# 'make -f build/Makefile' from the 'output' directory.

SHELL=/bin/bash
ifeq ($(CXX),)
  CXX=g++
endif
PKGCONFIG := /opt/ibm/InfoSphere_Streams/4.2.1.1/bin/dst-pe-pkg-config.sh
SPL_BUNDLE_BUILDER := /opt/ibm/InfoSphere_Streams/4.2.1.1/system/impl/bin/spl-bundle-builder
SO_INCLUDE := $(shell $(PKGCONFIG) --cflags dst-spl-pe-install)
SO_LIB := $(shell $(PKGCONFIG) --libs dst-spl-pe-install)
SO_STAND_LIB := $(shell $(PKGCONFIG) --libs dst-spl-pe-install-standalone)
SPL_CXXFLAGS = -Wall -Wno-unused -Wno-sign-compare
SPL_CXXFLAGS += -D_REENTRANT -fPIC -finline-functions -fmessage-length=0
SPL_CXXFLAGS += $(SO_INCLUDE) -O3 -DNDEBUG  -std=gnu++98 
SPL_LDFLAGS = $(SO_LIB)

SPL_TYPES = build/type/BeJwrMco0rMg0K0otLs0pAQAgzAT3.o \
            build/type/BeJwrMcm0zM3MC0otLs0pATITK2DMxLJ0GLO4NBfCBAClbRJK.o 
SPL_FUNCTIONS = 
SPL_OPERATORS = build/operator/DataGenerator.o \
                build/operator/StateKeeper.o \
                build/operator/MySink1.o \
                build/operator/ResultAggregator.o \
                build/operator/mySink2.o 
SPL_SO_BINS = bin/DataGenerator.so \
              bin/StateKeeper.so \
              bin/MySink1.so \
              bin/ResultAggregator.so \
              bin/mySink2.so 

SPL_ADL_FILE = com.vz.soi.SimpleState.adl

SPL_OUTPUT_DIR_ROOT = $(shell printf '%q' '/home/streamsadmin/soi/003_simple_state/output/com.vz.soi.SimpleState')
SPL_OUTPUT_DIR = $(shell printf '%q' 'BuildConfig')

.PHONY: distclean clean all types functions operators sos bundle toolkits standalone sablink

all: bin types functions operators sos standalone bundle sablink

distclean clean:
	@rm -fr bin/* build/type build/function build/operator build/bundle build/standalone com.vz.soi.SimpleState.sab

bin:
	@mkdir -m 775 bin

types: $(SPL_TYPES)

build/type/BeJwrMco0rMg0K0otLs0pAQAgzAT3.o: \
	    src/type/BeJwrMco0rMg0K0otLs0pAQAgzAT3.h \
	    src/type/BeJwrMco0rMg0K0otLs0pAQAgzAT3.cpp \
	    build/cppOptions \
	    | build/type
	@echo ' [CXX-type] tuple<int32 x,int32 result>'
	@$(CXX) -o $@ -c $(SPL_CXXFLAGS) src/type/BeJwrMco0rMg0K0otLs0pAQAgzAT3.cpp

build/type/BeJwrMcm0zM3MC0otLs0pATITK2DMxLJ0GLO4NBfCBAClbRJK.o: \
	    src/type/BeJwrMcm0zM3MC0otLs0pATITK2DMxLJ0GLO4NBfCBAClbRJK.h \
	    src/type/BeJwrMcm0zM3MC0otLs0pATITK2DMxLJ0GLO4NBfCBAClbRJK.cpp \
	    build/cppOptions \
	    | build/type
	@echo ' [CXX-type] tuple<int32 minResult,int32 maxResult,int32 avgResult,int32 sumResult>'
	@$(CXX) -o $@ -c $(SPL_CXXFLAGS) src/type/BeJwrMcm0zM3MC0otLs0pATITK2DMxLJ0GLO4NBfCBAClbRJK.cpp

build/type:
	-@mkdir -m 775 build/type

operators: $(SPL_OPERATORS)

-include build/operator/DataGenerator.d
build/operator/DataGenerator.o: \
	    src/operator/DataGenerator.h \
	    src/operator/DataGenerator.cpp\
	    build/dep/operator/DataGenerator.dep  \
	    build/cppOptions \
	    | build/operator
	@echo ' [CXX-operator] DataGenerator'
	@$(CXX) -o $@ -MD -I /opt/ibm/InfoSphere_Streams/4.2.1.1/toolkits/spl/impl/nl/include -DSPLJAVAFUNCTION_ADL_FILENAME=\"com.vz.soi.SimpleState.adl\" -c $(SPL_CXXFLAGS) src/operator/DataGenerator.cpp

-include build/operator/StateKeeper.d
build/operator/StateKeeper.o: \
	    src/operator/StateKeeper.h \
	    src/operator/StateKeeper.cpp\
	    build/dep/operator/StateKeeper.dep  \
	    build/cppOptions \
	    | build/operator
	@echo ' [CXX-operator] StateKeeper'
	@$(CXX) -o $@ -MD -I /opt/ibm/InfoSphere_Streams/4.2.1.1/toolkits/spl/impl/nl/include -DSPLJAVAFUNCTION_ADL_FILENAME=\"com.vz.soi.SimpleState.adl\" -c $(SPL_CXXFLAGS) src/operator/StateKeeper.cpp

-include build/operator/MySink1.d
build/operator/MySink1.o: \
	    src/operator/MySink1.h \
	    src/operator/MySink1.cpp\
	    build/dep/operator/MySink1.dep  \
	    build/cppOptions \
	    | build/operator
	@echo ' [CXX-operator] MySink1'
	@$(CXX) -o $@ -MD -I /opt/ibm/InfoSphere_Streams/4.2.1.1/toolkits/spl/impl/nl/include -I /opt/ibm/InfoSphere_Streams/4.2.1.1/toolkits/spl/impl/include -DSPLJAVAFUNCTION_ADL_FILENAME=\"com.vz.soi.SimpleState.adl\" -c $(SPL_CXXFLAGS) src/operator/MySink1.cpp

-include build/operator/ResultAggregator.d
build/operator/ResultAggregator.o: \
	    src/operator/ResultAggregator.h \
	    src/operator/ResultAggregator.cpp\
	    build/dep/operator/ResultAggregator.dep  \
	    build/cppOptions \
	    | build/operator
	@echo ' [CXX-operator] ResultAggregator'
	@$(CXX) -o $@ -MD -I /opt/ibm/InfoSphere_Streams/4.2.1.1/toolkits/spl/impl/nl/include -I /opt/ibm/InfoSphere_Streams/4.2.1.1/toolkits/spl/impl/include -DSPLJAVAFUNCTION_ADL_FILENAME=\"com.vz.soi.SimpleState.adl\" -c $(SPL_CXXFLAGS) src/operator/ResultAggregator.cpp

-include build/operator/mySink2.d
build/operator/mySink2.o: \
	    src/operator/mySink2.h \
	    src/operator/mySink2.cpp\
	    build/dep/operator/mySink2.dep  \
	    build/cppOptions \
	    | build/operator
	@echo ' [CXX-operator] mySink2'
	@$(CXX) -o $@ -MD -I /opt/ibm/InfoSphere_Streams/4.2.1.1/toolkits/spl/impl/nl/include -DSPLJAVAFUNCTION_ADL_FILENAME=\"com.vz.soi.SimpleState.adl\" -c $(SPL_CXXFLAGS) src/operator/mySink2.cpp

build/operator:
	-@mkdir -m 775 -p build/operator

functions: $(SPL_FUNCTIONS)

sos: $(SPL_SO_BINS)

SODataGenerator = \
	    build/operator/DataGenerator.o \
	    build/type/BeJwrMco0rMg0K0otLs0pAQAgzAT3.o 

bin/DataGenerator.so: \
	$(SODataGenerator) \
	build/dep/DataGenerator.so \
	build/ldOptions
	@echo ' [LD-so] so DataGenerator'
	@$(CXX) $(SPL_CXXFLAGS) -o bin/DataGenerator.so -fPIC -shared $(SODataGenerator) $(SPL_LDFLAGS)

SOStateKeeper = \
	    build/operator/StateKeeper.o \
	    build/type/BeJwrMco0rMg0K0otLs0pAQAgzAT3.o 

bin/StateKeeper.so: \
	$(SOStateKeeper) \
	build/dep/StateKeeper.so \
	build/ldOptions
	@echo ' [LD-so] so StateKeeper'
	@$(CXX) $(SPL_CXXFLAGS) -o bin/StateKeeper.so -fPIC -shared $(SOStateKeeper) $(SPL_LDFLAGS)

SOMySink1 = \
	    build/operator/MySink1.o \
	    build/type/BeJwrMco0rMg0K0otLs0pAQAgzAT3.o 

bin/MySink1.so: \
	$(SOMySink1) \
	build/dep/MySink1.so \
	build/ldOptions
	@echo ' [LD-so] so MySink1'
	@$(CXX) $(SPL_CXXFLAGS) -o bin/MySink1.so -fPIC -shared $(SOMySink1) -lstreams-stdtk-runtime -lstreams_boost_iostreams -lstreams_boost_filesystem -lstreams_boost_system $(SPL_LDFLAGS)

SOResultAggregator = \
	    build/operator/ResultAggregator.o \
	    build/type/BeJwrMcm0zM3MC0otLs0pATITK2DMxLJ0GLO4NBfCBAClbRJK.o \
	    build/type/BeJwrMco0rMg0K0otLs0pAQAgzAT3.o 

bin/ResultAggregator.so: \
	$(SOResultAggregator) \
	build/dep/ResultAggregator.so \
	build/ldOptions
	@echo ' [LD-so] so ResultAggregator'
	@$(CXX) $(SPL_CXXFLAGS) -o bin/ResultAggregator.so -fPIC -shared $(SOResultAggregator) -lstreams-stdtk-runtime $(SPL_LDFLAGS)

SOmySink2 = \
	    build/operator/mySink2.o \
	    build/type/BeJwrMcm0zM3MC0otLs0pATITK2DMxLJ0GLO4NBfCBAClbRJK.o 

bin/mySink2.so: \
	$(SOmySink2) \
	build/dep/mySink2.so \
	build/ldOptions
	@echo ' [LD-so] so mySink2'
	@$(CXX) $(SPL_CXXFLAGS) -o bin/mySink2.so -fPIC -shared $(SOmySink2) $(SPL_LDFLAGS)

standalone: bin/standalone.exe

build/standalone/standalone.o: \
	    src/standalone/standalone.h \
	    src/standalone/standalone.cpp  \
	    build/cppOptions \
	    | build/standalone
	@echo ' [CXX-standalone] standalone'
	@$(CXX) -o $@ -c $(SPL_CXXFLAGS) src/standalone/standalone.cpp

bin/standalone.exe: build/standalone/standalone.o build/ldOptions
	@echo ' [LD-standalone] standalone'
	@$(CXX) $(SPL_CXXFLAGS) -o bin/standalone.exe build/standalone/standalone.o $(SO_STAND_LIB)
	@echo ' [LN-standalone] standalone '
	@ln -sf standalone bin/com.vz.soi.SimpleState
build/standalone:
	-@mkdir -m 775 build/standalone

sablink:

	@ln -sf ../com.vz.soi.SimpleState.sab bin/sab

bundle: com.vz.soi.SimpleState.sab

-include build/dep/com.vz.soi.SimpleState.sab.d
com.vz.soi.SimpleState.sab: $(SPL_SO_BINS) $(SPL_ADL_FILE) build/dep/com.vz.soi.SimpleState.sab.d bin/standalone.exe
	@echo ' [Bundle] com.vz.soi.SimpleState.sab'
	@$(SPL_BUNDLE_BUILDER) $(SPL_OUTPUT_DIR_ROOT) $(SPL_OUTPUT_DIR) $(SPL_ADL_FILE) com.vz.soi.SimpleState.sab

