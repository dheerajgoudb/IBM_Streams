// eJyVkEFPwzAMheW_1MnFuksIB9TYGO0wbmpT2wGkKqttaTZOQpGzl15OVMbQj8slPtr_13HJzOVK1cRF8Ua9IoyfQggKcSsMgyFieH7Ak3R7_0TfT5Vn7uyqaayP_0235Vuc5NdGSp5LfhCvkvdx2a6q1fHjOesW6UQOmuIdB7nfFoUP0ZNpYdbEjzaSifc5ALDODsjSBKohqHogw4Ilxnl_0wMFpOyEeGtLJJ6tVVGCswfP9pCGIW4C4UF9OzmMIZA00egwd3ELFxcgyprX3MeLaI87ZyVl_1tf3_17EDg5w8CPIBRA8KvM9UinOmPECnqP71FU6O_1tvwbD8F_1Bf





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

#include "../type/BeJwrMSk2yUvMTfUyTkxPLTYtySzJSS02S0_1NS0ktAgCUCwqD.h"


#define MY_OPERATOR MySink1$OP
#define MY_BASE_OPERATOR MySink1_Base
#define MY_OPERATOR_SCOPE SPL::_Operator

namespace SPL {
namespace _Operator {

class MY_BASE_OPERATOR : public Operator
{
public:
    
    typedef SPL::BeJwrMSk2yUvMTfUyTkxPLTYtySzJSS02S0_1NS0ktAgCUCwqD IPort0Type;
    
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

