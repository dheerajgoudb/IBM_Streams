// eJyVkM1OwzAQhLWvUnGO46TiJ7cQ0UNDRCG5I7vZEquObdaOIG_0PGwpSj9XeRrsz36x3OhG9cAGpKDZKY6vMETikcTiskoSF2SF7xO0XNe06q2_1vmm5Pu7ZrQt24pjtmc1d9hofqvu58vi1fKylLekuGVXTIQKtwk0K7ey4K8oGU_0YBF47_1apEzIMwBggx2RxQ0Uoxf9qAzzVrE0Xb97Fw9YL4IAYw2eXA8RFPilLT9nPX07Qu_0VNXDQkx_1gMoqf48sQz_0QUcEOIS2HlLP3DXl0YFNDyNYAc_1DxKq_0EPzZHaY6Sx4kQgp_1mFWtQapLUahYH0B0kdHbj





#ifndef SPL_OPER_INSTANCE_MYSINK1_H_
#define SPL_OPER_INSTANCE_MYSINK1_H_

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <fstream>
#include <streams_boost/iostreams/stream.hpp>
#include <streams_boost/iostreams/filtering_streambuf.hpp>
#include <SPL/Runtime/Common/Metric.h>
#include <streams_boost/iostreams/device/file_descriptor.hpp>
#include <SPL/Runtime/Operator/Operator.h>
#include <SPL/Runtime/Operator/ParameterValue.h>
#include <SPL/Runtime/Operator/OperatorContext.h>
#include <SPL/Runtime/Operator/OperatorMetrics.h>
#include <SPL/Runtime/Operator/Port/AutoPortMutex.h>
#include <SPL/Runtime/Operator/State/StateHandler.h>
#include <SPL/Runtime/ProcessingElement/PE.h>
#include <SPL/Runtime/Type/SPLType.h>
#include <SPL/Runtime/Utility/CV.h>
using namespace UTILS_NAMESPACE;

#include "../type/BeJwrMS42K67MTcrPSTMtKMpMTk2yTCqt9C8KTs3JAQCbbArR.h"


#define MY_OPERATOR MySink1$OP
#define MY_BASE_OPERATOR MySink1_Base
#define MY_OPERATOR_SCOPE SPL::_Operator

namespace SPL {
namespace _Operator {

class MY_BASE_OPERATOR : public Operator
{
public:
    
    typedef SPL::BeJwrMS42K67MTcrPSTMtKMpMTk2yTCqt9C8KTs3JAQCbbArR IPort0Type;
    
    MY_BASE_OPERATOR();
    
    ~MY_BASE_OPERATOR();
    
    inline void tupleLogic(Tuple const & tuple, uint32_t port);
    void processRaw(Tuple const & tuple, uint32_t port);
    
    inline void punctLogic(Punctuation const & punct, uint32_t port);
    void processRaw(Punctuation const & punct, uint32_t port);
    void punctPermitProcessRaw(Punctuation const & punct, uint32_t port);
    void punctNoPermitProcessRaw(Punctuation const & punct, uint32_t port);
    
    
    
    SPL::rstring lit$0;
    SPL::uint32 lit$1;
    
    
protected:
    Mutex $svMutex;
    void checkpointStateVariables(NetworkByteBuffer & opstate) const;
    void restoreStateVariables(NetworkByteBuffer & opstate);
    void checkpointStateVariables(Checkpoint & ckpt);
    void resetStateVariables(Checkpoint & ckpt);
    void resetStateVariablesToInitialState();
    bool hasStateVariables() const;
    void resetToInitialStateRaw();
    void checkpointRaw(Checkpoint & ckpt);
    void resetRaw(Checkpoint & ckpt);
private:
    static bool globalInit_;
    static bool globalIniter();
    ParameterMapType paramValues_;
    ParameterMapType& getParameters() { return paramValues_;}
    void addParameterValue(std::string const & param, ConstValueHandle const& value)
    {
        ParameterMapType::iterator it = paramValues_.find(param);
        if (it == paramValues_.end())
            it = paramValues_.insert (std::make_pair (param, ParameterValueListType())).first;
        it->second.push_back(&ParameterValue::create(value));
    }
    void addParameterValue(std::string const & param)
    {
        ParameterMapType::iterator it = paramValues_.find(param);
        if (it == paramValues_.end())
            it = paramValues_.insert (std::make_pair (param, ParameterValueListType())).first;
        it->second.push_back(&ParameterValue::create());
    }
};


class MY_OPERATOR : public MY_BASE_OPERATOR 
{
  public:
    MY_OPERATOR();

    virtual void prepareToShutdown();

    void process(Tuple const & tuple, uint32_t port);
    
    
        void process(Punctuation const & punct, uint32_t port);
    
    
  private:
    class Helper {
        public:
            Helper (const std::string& fName, bool restoring
                    
                    );
            
                std::ostream& fs() { return _fs; }
                std::ostream& writeTo() { return _fs; }
            
            void flush() { _fs.flush(); }
            int fd() { return _fd; }
            streams_boost::iostreams::filtering_streambuf<streams_boost::iostreams::output>& filt_str()
                { return _filt_str; }
        private:
            std::auto_ptr<streams_boost::iostreams::file_descriptor_sink> _fd_sink;
            std::ostream _fs;
            streams_boost::iostreams::filtering_streambuf<streams_boost::iostreams::output> _filt_str;
            
            
            int _fd;
    };


    
    

    std::string genFilename();
    std::string makeAbsolute(const std::string & path);
    void openFile(bool restoring);
    void closeFile();
    Mutex _mutex;
    volatile bool _shutdown;
    std::string _pathName;
    std::string _pattern;
    Metric& _numFilesOpenedMetric;
    Metric& _numTupleWriteErrorsMetric;
    std::auto_ptr<Helper> _f;
    uint32_t _fileGeneration;
    
    
    uint64_t _tuplesUntilFlush, _flushCount;
    
    
    
    
    

    

    // Position of the file on a checkpoint/restore
    uint64_t _ckptOffset;
    bool _resetting;
}; 

} // namespace _Operator
} // namespace SPL

#undef MY_OPERATOR_SCOPE
#undef MY_BASE_OPERATOR
#undef MY_OPERATOR
#endif // SPL_OPER_INSTANCE_MYSINK1_H_

