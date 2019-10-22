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

SPL_TYPES = build/type/BeJwrMS42K67MTcrPSTMtKMpMTk2yTCqt9C8KTs3JAQCbbArR.o 
SPL_FUNCTIONS = 
SPL_OPERATORS = build/operator/TickerGenerator.o \
                build/operator/StockSplitter.o \
                build/operator/MySink1.o 
SPL_SO_BINS = bin/TickerGenerator.so \
              bin/StockSplitter.so \
              bin/MySink1.so 

SPL_ADL_FILE = com.vz.soi.mySplit.adl

SPL_OUTPUT_DIR_ROOT = $(shell printf '%q' '/home/streamsadmin/soi/004_split/output/com.vz.soi.mySplit')
SPL_OUTPUT_DIR = $(shell printf '%q' 'BuildConfig')

.PHONY: distclean clean all types functions operators sos bundle toolkits standalone sablink

all: bin types functions operators sos standalone bundle sablink

distclean clean:
	@rm -fr bin/* build/type build/function build/operator build/bundle build/standalone com.vz.soi.mySplit.sab

bin:
	@mkdir -m 775 bin

types: $(SPL_TYPES)

build/type/BeJwrMS42K67MTcrPSTMtKMpMTk2yTCqt9C8KTs3JAQCbbArR.o: \
	    src/type/BeJwrMS42K67MTcrPSTMtKMpMTk2yTCqt9C8KTs3JAQCbbArR.h \
	    src/type/BeJwrMS42K67MTcrPSTMtKMpMTk2yTCqt9C8KTs3JAQCbbArR.cpp \
	    build/cppOptions \
	    | build/type
	@echo ' [CXX-type] tuple<rstring symbol,float32 price,boolean buyOrSell>'
	@$(CXX) -o $@ -c $(SPL_CXXFLAGS) src/type/BeJwrMS42K67MTcrPSTMtKMpMTk2yTCqt9C8KTs3JAQCbbArR.cpp

build/type:
	-@mkdir -m 775 build/type

operators: $(SPL_OPERATORS)

-include build/operator/TickerGenerator.d
build/operator/TickerGenerator.o: \
	    src/operator/TickerGenerator.h \
	    src/operator/TickerGenerator.cpp\
	    build/dep/operator/TickerGenerator.dep  \
	    build/cppOptions \
	    | build/operator
	@echo ' [CXX-operator] TickerGenerator'
	@$(CXX) -o $@ -MD -I /opt/ibm/InfoSphere_Streams/4.2.1.1/toolkits/spl/impl/nl/include -I /opt/ibm/InfoSphere_Streams/4.2.1.1/toolkits/spl/impl/include -DSPLJAVAFUNCTION_ADL_FILENAME=\"com.vz.soi.mySplit.adl\" -c $(SPL_CXXFLAGS) src/operator/TickerGenerator.cpp

-include build/operator/StockSplitter.d
build/operator/StockSplitter.o: \
	    src/operator/StockSplitter.h \
	    src/operator/StockSplitter.cpp\
	    build/dep/operator/StockSplitter.dep  \
	    build/cppOptions \
	    | build/operator
	@echo ' [CXX-operator] StockSplitter'
	@$(CXX) -o $@ -MD -I /opt/ibm/InfoSphere_Streams/4.2.1.1/toolkits/spl/impl/nl/include -I /opt/ibm/InfoSphere_Streams/4.2.1.1/toolkits/spl/impl/include -DSPLJAVAFUNCTION_ADL_FILENAME=\"com.vz.soi.mySplit.adl\" -c $(SPL_CXXFLAGS) src/operator/StockSplitter.cpp

-include build/operator/MySink1.d
build/operator/MySink1.o: \
	    src/operator/MySink1.h \
	    src/operator/MySink1.cpp\
	    build/dep/operator/MySink1.dep  \
	    build/cppOptions \
	    | build/operator
	@echo ' [CXX-operator] MySink1'
	@$(CXX) -o $@ -MD -I /opt/ibm/InfoSphere_Streams/4.2.1.1/toolkits/spl/impl/nl/include -I /opt/ibm/InfoSphere_Streams/4.2.1.1/toolkits/spl/impl/include -DSPLJAVAFUNCTION_ADL_FILENAME=\"com.vz.soi.mySplit.adl\" -c $(SPL_CXXFLAGS) src/operator/MySink1.cpp

build/operator:
	-@mkdir -m 775 -p build/operator

functions: $(SPL_FUNCTIONS)

sos: $(SPL_SO_BINS)

SOTickerGenerator = \
	    build/operator/TickerGenerator.o \
	    build/type/BeJwrMS42K67MTcrPSTMtKMpMTk2yTCqt9C8KTs3JAQCbbArR.o 

bin/TickerGenerator.so: \
	$(SOTickerGenerator) \
	build/dep/TickerGenerator.so \
	build/ldOptions
	@echo ' [LD-so] so TickerGenerator'
	@$(CXX) $(SPL_CXXFLAGS) -o bin/TickerGenerator.so -fPIC -shared $(SOTickerGenerator) -lstreams-stdtk-runtime -lstreams_boost_iostreams -lstreams_boost_filesystem -lstreams_boost_system $(SPL_LDFLAGS)

SOStockSplitter = \
	    build/operator/StockSplitter.o \
	    build/type/BeJwrMS42K67MTcrPSTMtKMpMTk2yTCqt9C8KTs3JAQCbbArR.o 

bin/StockSplitter.so: \
	$(SOStockSplitter) \
	build/dep/StockSplitter.so \
	build/ldOptions
	@echo ' [LD-so] so StockSplitter'
	@$(CXX) $(SPL_CXXFLAGS) -o bin/StockSplitter.so -fPIC -shared $(SOStockSplitter) -lstreams-stdtk-runtime $(SPL_LDFLAGS)

SOMySink1 = \
	    build/operator/MySink1.o \
	    build/type/BeJwrMS42K67MTcrPSTMtKMpMTk2yTCqt9C8KTs3JAQCbbArR.o 

bin/MySink1.so: \
	$(SOMySink1) \
	build/dep/MySink1.so \
	build/ldOptions
	@echo ' [LD-so] so MySink1'
	@$(CXX) $(SPL_CXXFLAGS) -o bin/MySink1.so -fPIC -shared $(SOMySink1) -lstreams-stdtk-runtime -lstreams_boost_iostreams -lstreams_boost_filesystem -lstreams_boost_system $(SPL_LDFLAGS)

SOMySink2 = \
	    build/operator/MySink1.o \
	    build/type/BeJwrMS42K67MTcrPSTMtKMpMTk2yTCqt9C8KTs3JAQCbbArR.o 

bin/MySink2.so: \
	$(SOMySink2) \
	build/dep/MySink2.so \
	build/ldOptions
	@echo ' [LD-so] so MySink2'
	@$(CXX) $(SPL_CXXFLAGS) -o bin/MySink2.so -fPIC -shared $(SOMySink2) -lstreams-stdtk-runtime -lstreams_boost_iostreams -lstreams_boost_filesystem -lstreams_boost_system $(SPL_LDFLAGS)

SOMySink3 = \
	    build/operator/MySink1.o \
	    build/type/BeJwrMS42K67MTcrPSTMtKMpMTk2yTCqt9C8KTs3JAQCbbArR.o 

bin/MySink3.so: \
	$(SOMySink3) \
	build/dep/MySink3.so \
	build/ldOptions
	@echo ' [LD-so] so MySink3'
	@$(CXX) $(SPL_CXXFLAGS) -o bin/MySink3.so -fPIC -shared $(SOMySink3) -lstreams-stdtk-runtime -lstreams_boost_iostreams -lstreams_boost_filesystem -lstreams_boost_system $(SPL_LDFLAGS)

SOMySink4 = \
	    build/operator/MySink1.o \
	    build/type/BeJwrMS42K67MTcrPSTMtKMpMTk2yTCqt9C8KTs3JAQCbbArR.o 

bin/MySink4.so: \
	$(SOMySink4) \
	build/dep/MySink4.so \
	build/ldOptions
	@echo ' [LD-so] so MySink4'
	@$(CXX) $(SPL_CXXFLAGS) -o bin/MySink4.so -fPIC -shared $(SOMySink4) -lstreams-stdtk-runtime -lstreams_boost_iostreams -lstreams_boost_filesystem -lstreams_boost_system $(SPL_LDFLAGS)

SOMySink5 = \
	    build/operator/MySink1.o \
	    build/type/BeJwrMS42K67MTcrPSTMtKMpMTk2yTCqt9C8KTs3JAQCbbArR.o 

bin/MySink5.so: \
	$(SOMySink5) \
	build/dep/MySink5.so \
	build/ldOptions
	@echo ' [LD-so] so MySink5'
	@$(CXX) $(SPL_CXXFLAGS) -o bin/MySink5.so -fPIC -shared $(SOMySink5) -lstreams-stdtk-runtime -lstreams_boost_iostreams -lstreams_boost_filesystem -lstreams_boost_system $(SPL_LDFLAGS)

SOMySink6 = \
	    build/operator/MySink1.o \
	    build/type/BeJwrMS42K67MTcrPSTMtKMpMTk2yTCqt9C8KTs3JAQCbbArR.o 

bin/MySink6.so: \
	$(SOMySink6) \
	build/dep/MySink6.so \
	build/ldOptions
	@echo ' [LD-so] so MySink6'
	@$(CXX) $(SPL_CXXFLAGS) -o bin/MySink6.so -fPIC -shared $(SOMySink6) -lstreams-stdtk-runtime -lstreams_boost_iostreams -lstreams_boost_filesystem -lstreams_boost_system $(SPL_LDFLAGS)

SOMySink7 = \
	    build/operator/MySink1.o \
	    build/type/BeJwrMS42K67MTcrPSTMtKMpMTk2yTCqt9C8KTs3JAQCbbArR.o 

bin/MySink7.so: \
	$(SOMySink7) \
	build/dep/MySink7.so \
	build/ldOptions
	@echo ' [LD-so] so MySink7'
	@$(CXX) $(SPL_CXXFLAGS) -o bin/MySink7.so -fPIC -shared $(SOMySink7) -lstreams-stdtk-runtime -lstreams_boost_iostreams -lstreams_boost_filesystem -lstreams_boost_system $(SPL_LDFLAGS)

SOMySink8 = \
	    build/operator/MySink1.o \
	    build/type/BeJwrMS42K67MTcrPSTMtKMpMTk2yTCqt9C8KTs3JAQCbbArR.o 

bin/MySink8.so: \
	$(SOMySink8) \
	build/dep/MySink8.so \
	build/ldOptions
	@echo ' [LD-so] so MySink8'
	@$(CXX) $(SPL_CXXFLAGS) -o bin/MySink8.so -fPIC -shared $(SOMySink8) -lstreams-stdtk-runtime -lstreams_boost_iostreams -lstreams_boost_filesystem -lstreams_boost_system $(SPL_LDFLAGS)

SOMySink9 = \
	    build/operator/MySink1.o \
	    build/type/BeJwrMS42K67MTcrPSTMtKMpMTk2yTCqt9C8KTs3JAQCbbArR.o 

bin/MySink9.so: \
	$(SOMySink9) \
	build/dep/MySink9.so \
	build/ldOptions
	@echo ' [LD-so] so MySink9'
	@$(CXX) $(SPL_CXXFLAGS) -o bin/MySink9.so -fPIC -shared $(SOMySink9) -lstreams-stdtk-runtime -lstreams_boost_iostreams -lstreams_boost_filesystem -lstreams_boost_system $(SPL_LDFLAGS)

SOMySink10 = \
	    build/operator/MySink1.o \
	    build/type/BeJwrMS42K67MTcrPSTMtKMpMTk2yTCqt9C8KTs3JAQCbbArR.o 

bin/MySink10.so: \
	$(SOMySink10) \
	build/dep/MySink10.so \
	build/ldOptions
	@echo ' [LD-so] so MySink10'
	@$(CXX) $(SPL_CXXFLAGS) -o bin/MySink10.so -fPIC -shared $(SOMySink10) -lstreams-stdtk-runtime -lstreams_boost_iostreams -lstreams_boost_filesystem -lstreams_boost_system $(SPL_LDFLAGS)

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
	@ln -sf standalone bin/com.vz.soi.mySplit
build/standalone:
	-@mkdir -m 775 build/standalone

sablink:

	@ln -sf ../com.vz.soi.mySplit.sab bin/sab

bundle: com.vz.soi.mySplit.sab

-include build/dep/com.vz.soi.mySplit.sab.d
com.vz.soi.mySplit.sab: $(SPL_SO_BINS) $(SPL_ADL_FILE) build/dep/com.vz.soi.mySplit.sab.d bin/standalone.exe
	@echo ' [Bundle] com.vz.soi.mySplit.sab'
	@$(SPL_BUNDLE_BUILDER) $(SPL_OUTPUT_DIR_ROOT) $(SPL_OUTPUT_DIR) $(SPL_ADL_FILE) com.vz.soi.mySplit.sab

