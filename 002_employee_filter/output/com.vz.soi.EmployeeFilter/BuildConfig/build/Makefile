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

SPL_TYPES = build/type/BeJyrNI03Ti4uMy6pKDFOyswzTcrJT842ycnMSwUAf_1wJCo.o \
            build/type/BeJwrMSk2yUvMTfUyTkxPLTYtySzJSS02S0_1NS0ktAgCUCwqD.o \
            build/type/BeJwrMS02yUvMTfUyTkxPLTYtySzJSS02S0_1NS0ktcjNNys8rLQYA5zcNAm.o 
SPL_FUNCTIONS = 
SPL_OPERATORS = build/operator/Employee.o \
                build/operator/FilteredEmployee.o \
                build/operator/MySink1.o \
                build/operator/EmployeeWithBonus.o \
                build/operator/MySink2.o \
                build/operator/CustomBonusCalculator.o 
SPL_SO_BINS = bin/Employee.so \
              bin/FilteredEmployee.so \
              bin/MySink1.so \
              bin/EmployeeWithBonus.so \
              bin/MySink2.so \
              bin/CustomBonusCalculator.so 

SPL_ADL_FILE = com.vz.soi.EmployeeFilter.adl

SPL_OUTPUT_DIR_ROOT = $(shell printf '%q' '/home/streamsadmin/soi/002_employee_filter/output/com.vz.soi.EmployeeFilter')
SPL_OUTPUT_DIR = $(shell printf '%q' 'BuildConfig')

.PHONY: distclean clean all types functions operators sos bundle toolkits standalone sablink

all: bin types functions operators sos standalone bundle sablink

distclean clean:
	@rm -fr bin/* build/type build/function build/operator build/bundle build/standalone com.vz.soi.EmployeeFilter.sab

bin:
	@mkdir -m 775 bin

types: $(SPL_TYPES)

build/type/BeJyrNI03Ti4uMy6pKDFOyswzTcrJT842ycnMSwUAf_1wJCo.o: \
	    src/type/BeJyrNI03Ti4uMy6pKDFOyswzTcrJT842ycnMSwUAf_1wJCo.h \
	    src/type/BeJyrNI03Ti4uMy6pKDFOyswzTcrJT842ycnMSwUAf_1wJCo.cpp \
	    build/cppOptions \
	    | build/type
	@echo ' [CXX-type] enum{csv,txt,bin,block,line}'
	@$(CXX) -o $@ -c $(SPL_CXXFLAGS) src/type/BeJyrNI03Ti4uMy6pKDFOyswzTcrJT842ycnMSwUAf_1wJCo.cpp

build/type/BeJwrMSk2yUvMTfUyTkxPLTYtySzJSS02S0_1NS0ktAgCUCwqD.o: \
	    src/type/BeJwrMSk2yUvMTfUyTkxPLTYtySzJSS02S0_1NS0ktAgCUCwqD.h \
	    src/type/BeJwrMSk2yUvMTfUyTkxPLTYtySzJSS02S0_1NS0ktAgCUCwqD.cpp \
	    build/cppOptions \
	    | build/type
	@echo ' [CXX-type] tuple<rstring name,uint8 age,rstring title,rstring gender>'
	@$(CXX) -o $@ -c $(SPL_CXXFLAGS) src/type/BeJwrMSk2yUvMTfUyTkxPLTYtySzJSS02S0_1NS0ktAgCUCwqD.cpp

build/type/BeJwrMS02yUvMTfUyTkxPLTYtySzJSS02S0_1NS0ktcjNNys8rLQYA5zcNAm.o: \
	    src/type/BeJwrMS02yUvMTfUyTkxPLTYtySzJSS02S0_1NS0ktcjNNys8rLQYA5zcNAm.h \
	    src/type/BeJwrMS02yUvMTfUyTkxPLTYtySzJSS02S0_1NS0ktcjNNys8rLQYA5zcNAm.cpp \
	    build/cppOptions \
	    | build/type
	@echo ' [CXX-type] tuple<rstring name,uint8 age,rstring title,rstring gender,float64 bonus>'
	@$(CXX) -o $@ -c $(SPL_CXXFLAGS) src/type/BeJwrMS02yUvMTfUyTkxPLTYtySzJSS02S0_1NS0ktcjNNys8rLQYA5zcNAm.cpp

build/type:
	-@mkdir -m 775 build/type

operators: $(SPL_OPERATORS)

-include build/operator/Employee.d
build/operator/Employee.o: \
	    src/operator/Employee.h \
	    src/operator/Employee.cpp\
	    build/dep/operator/Employee.dep \
	    src/type/BeJyrNI03Ti4uMy6pKDFOyswzTcrJT842ycnMSwUAf_1wJCo.h  \
	    build/cppOptions \
	    | build/operator
	@echo ' [CXX-operator] Employee'
	@$(CXX) -o $@ -MD -I /opt/ibm/InfoSphere_Streams/4.2.1.1/toolkits/spl/impl/nl/include -I /opt/ibm/InfoSphere_Streams/4.2.1.1/toolkits/spl/impl/include -DSPLJAVAFUNCTION_ADL_FILENAME=\"com.vz.soi.EmployeeFilter.adl\" -c $(SPL_CXXFLAGS) src/operator/Employee.cpp

-include build/operator/FilteredEmployee.d
build/operator/FilteredEmployee.o: \
	    src/operator/FilteredEmployee.h \
	    src/operator/FilteredEmployee.cpp\
	    build/dep/operator/FilteredEmployee.dep  \
	    build/cppOptions \
	    | build/operator
	@echo ' [CXX-operator] FilteredEmployee'
	@$(CXX) -o $@ -MD -I /opt/ibm/InfoSphere_Streams/4.2.1.1/toolkits/spl/impl/nl/include -DSPLJAVAFUNCTION_ADL_FILENAME=\"com.vz.soi.EmployeeFilter.adl\" -c $(SPL_CXXFLAGS) src/operator/FilteredEmployee.cpp

-include build/operator/MySink1.d
build/operator/MySink1.o: \
	    src/operator/MySink1.h \
	    src/operator/MySink1.cpp\
	    build/dep/operator/MySink1.dep  \
	    build/cppOptions \
	    | build/operator
	@echo ' [CXX-operator] MySink1'
	@$(CXX) -o $@ -MD -I /opt/ibm/InfoSphere_Streams/4.2.1.1/toolkits/spl/impl/nl/include -I /opt/ibm/InfoSphere_Streams/4.2.1.1/toolkits/spl/impl/include -DSPLJAVAFUNCTION_ADL_FILENAME=\"com.vz.soi.EmployeeFilter.adl\" -c $(SPL_CXXFLAGS) src/operator/MySink1.cpp

-include build/operator/EmployeeWithBonus.d
build/operator/EmployeeWithBonus.o: \
	    src/operator/EmployeeWithBonus.h \
	    src/operator/EmployeeWithBonus.cpp\
	    build/dep/operator/EmployeeWithBonus.dep \
	    src/type/BeJwrMS02yUvMTfUyTkxPLTYtySzJSS02S0_1NS0ktcjNNys8rLQYA5zcNAm.h  \
	    build/cppOptions \
	    | build/operator
	@echo ' [CXX-operator] EmployeeWithBonus'
	@$(CXX) -o $@ -MD -I /opt/ibm/InfoSphere_Streams/4.2.1.1/toolkits/spl/impl/nl/include -DSPLJAVAFUNCTION_ADL_FILENAME=\"com.vz.soi.EmployeeFilter.adl\" -c $(SPL_CXXFLAGS) src/operator/EmployeeWithBonus.cpp

-include build/operator/MySink2.d
build/operator/MySink2.o: \
	    src/operator/MySink2.h \
	    src/operator/MySink2.cpp\
	    build/dep/operator/MySink2.dep  \
	    build/cppOptions \
	    | build/operator
	@echo ' [CXX-operator] MySink2'
	@$(CXX) -o $@ -MD -I /opt/ibm/InfoSphere_Streams/4.2.1.1/toolkits/spl/impl/nl/include -I /opt/ibm/InfoSphere_Streams/4.2.1.1/toolkits/spl/impl/include -DSPLJAVAFUNCTION_ADL_FILENAME=\"com.vz.soi.EmployeeFilter.adl\" -c $(SPL_CXXFLAGS) src/operator/MySink2.cpp

-include build/operator/CustomBonusCalculator.d
build/operator/CustomBonusCalculator.o: \
	    src/operator/CustomBonusCalculator.h \
	    src/operator/CustomBonusCalculator.cpp\
	    build/dep/operator/CustomBonusCalculator.dep \
	    src/type/BeJwrMS02yUvMTfUyTkxPLTYtySzJSS02S0_1NS0ktcjNNys8rLQYA5zcNAm.h  \
	    build/cppOptions \
	    | build/operator
	@echo ' [CXX-operator] CustomBonusCalculator'
	@$(CXX) -o $@ -MD -I /opt/ibm/InfoSphere_Streams/4.2.1.1/toolkits/spl/impl/nl/include -DSPLJAVAFUNCTION_ADL_FILENAME=\"com.vz.soi.EmployeeFilter.adl\" -c $(SPL_CXXFLAGS) src/operator/CustomBonusCalculator.cpp

build/operator:
	-@mkdir -m 775 -p build/operator

functions: $(SPL_FUNCTIONS)

sos: $(SPL_SO_BINS)

SOEmployee = \
	    build/operator/Employee.o \
	    build/type/BeJwrMSk2yUvMTfUyTkxPLTYtySzJSS02S0_1NS0ktAgCUCwqD.o \
	    build/type/BeJyrNI03Ti4uMy6pKDFOyswzTcrJT842ycnMSwUAf_1wJCo.o 

bin/Employee.so: \
	$(SOEmployee) \
	build/dep/Employee.so \
	build/ldOptions
	@echo ' [LD-so] so Employee'
	@$(CXX) $(SPL_CXXFLAGS) -o bin/Employee.so -fPIC -shared $(SOEmployee) -lstreams-stdtk-runtime -lstreams_boost_iostreams -lstreams_boost_filesystem -lstreams_boost_system $(SPL_LDFLAGS)

SOFilteredEmployee = \
	    build/operator/FilteredEmployee.o \
	    build/type/BeJwrMSk2yUvMTfUyTkxPLTYtySzJSS02S0_1NS0ktAgCUCwqD.o 

bin/FilteredEmployee.so: \
	$(SOFilteredEmployee) \
	build/dep/FilteredEmployee.so \
	build/ldOptions
	@echo ' [LD-so] so FilteredEmployee'
	@$(CXX) $(SPL_CXXFLAGS) -o bin/FilteredEmployee.so -fPIC -shared $(SOFilteredEmployee) $(SPL_LDFLAGS)

SOMySink1 = \
	    build/operator/MySink1.o \
	    build/type/BeJwrMSk2yUvMTfUyTkxPLTYtySzJSS02S0_1NS0ktAgCUCwqD.o 

bin/MySink1.so: \
	$(SOMySink1) \
	build/dep/MySink1.so \
	build/ldOptions
	@echo ' [LD-so] so MySink1'
	@$(CXX) $(SPL_CXXFLAGS) -o bin/MySink1.so -fPIC -shared $(SOMySink1) -lstreams-stdtk-runtime -lstreams_boost_iostreams -lstreams_boost_filesystem -lstreams_boost_system $(SPL_LDFLAGS)

SOEmployeeWithBonus = \
	    build/operator/EmployeeWithBonus.o \
	    build/type/BeJwrMSk2yUvMTfUyTkxPLTYtySzJSS02S0_1NS0ktAgCUCwqD.o \
	    build/type/BeJwrMS02yUvMTfUyTkxPLTYtySzJSS02S0_1NS0ktcjNNys8rLQYA5zcNAm.o 

bin/EmployeeWithBonus.so: \
	$(SOEmployeeWithBonus) \
	build/dep/EmployeeWithBonus.so \
	build/ldOptions
	@echo ' [LD-so] so EmployeeWithBonus'
	@$(CXX) $(SPL_CXXFLAGS) -o bin/EmployeeWithBonus.so -fPIC -shared $(SOEmployeeWithBonus) $(SPL_LDFLAGS)

SOMySink2 = \
	    build/operator/MySink2.o \
	    build/type/BeJwrMS02yUvMTfUyTkxPLTYtySzJSS02S0_1NS0ktcjNNys8rLQYA5zcNAm.o 

bin/MySink2.so: \
	$(SOMySink2) \
	build/dep/MySink2.so \
	build/ldOptions
	@echo ' [LD-so] so MySink2'
	@$(CXX) $(SPL_CXXFLAGS) -o bin/MySink2.so -fPIC -shared $(SOMySink2) -lstreams-stdtk-runtime -lstreams_boost_iostreams -lstreams_boost_filesystem -lstreams_boost_system $(SPL_LDFLAGS)

SOCustomBonusCalculator = \
	    build/operator/CustomBonusCalculator.o \
	    build/type/BeJwrMSk2yUvMTfUyTkxPLTYtySzJSS02S0_1NS0ktAgCUCwqD.o \
	    build/type/BeJwrMS02yUvMTfUyTkxPLTYtySzJSS02S0_1NS0ktcjNNys8rLQYA5zcNAm.o 

bin/CustomBonusCalculator.so: \
	$(SOCustomBonusCalculator) \
	build/dep/CustomBonusCalculator.so \
	build/ldOptions
	@echo ' [LD-so] so CustomBonusCalculator'
	@$(CXX) $(SPL_CXXFLAGS) -o bin/CustomBonusCalculator.so -fPIC -shared $(SOCustomBonusCalculator) $(SPL_LDFLAGS)

SOMySink3 = \
	    build/operator/MySink2.o \
	    build/type/BeJwrMS02yUvMTfUyTkxPLTYtySzJSS02S0_1NS0ktcjNNys8rLQYA5zcNAm.o 

bin/MySink3.so: \
	$(SOMySink3) \
	build/dep/MySink3.so \
	build/ldOptions
	@echo ' [LD-so] so MySink3'
	@$(CXX) $(SPL_CXXFLAGS) -o bin/MySink3.so -fPIC -shared $(SOMySink3) -lstreams-stdtk-runtime -lstreams_boost_iostreams -lstreams_boost_filesystem -lstreams_boost_system $(SPL_LDFLAGS)

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
	@ln -sf standalone bin/com.vz.soi.EmployeeFilter
build/standalone:
	-@mkdir -m 775 build/standalone

sablink:

	@ln -sf ../com.vz.soi.EmployeeFilter.sab bin/sab

bundle: com.vz.soi.EmployeeFilter.sab

-include build/dep/com.vz.soi.EmployeeFilter.sab.d
com.vz.soi.EmployeeFilter.sab: $(SPL_SO_BINS) $(SPL_ADL_FILE) build/dep/com.vz.soi.EmployeeFilter.sab.d bin/standalone.exe
	@echo ' [Bundle] com.vz.soi.EmployeeFilter.sab'
	@$(SPL_BUNDLE_BUILDER) $(SPL_OUTPUT_DIR_ROOT) $(SPL_OUTPUT_DIR) $(SPL_ADL_FILE) com.vz.soi.EmployeeFilter.sab

