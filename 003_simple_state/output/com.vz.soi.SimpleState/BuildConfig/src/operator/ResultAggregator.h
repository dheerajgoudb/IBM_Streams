// eJyNkEtvwjAQhLV_1BfXQXuKFcMotUKlqHn0Ad_0TC1ljyI7IdmvLra4qCoK2qaG_0r_1WZmxzcqcaR4kNZwlWW5EI4EDwRjwDgTGCUJC58NsRkVH67eaDzUaT1HGyqPTb56XJWT_07qrCnyonqdPs_1f5LJ_0rt0VRJrvRL9qiqwWWPf2ai0O_0So_0XGB2VDDcIy5cqy6QJ6QQA2M5qYj444trzrZaGeSsZYrr2UjeK1j7EuGzLAwdjDeG3EoJsrDur_1esOEtwRwo1tTYDxhX8f6TgQy_0jgtHfkWxWgP0Kwf7gNbwp0TDCF_0NziSriWJqpf5Dm_1lQgK61OK2zvQvPsB8m4QyPfiGsz35LigQbBv9TW8bPUQMPb1BbKnLyX




#ifndef SPL_OPER_INSTANCE_RESULTAGGREGATOR_H_
#define SPL_OPER_INSTANCE_RESULTAGGREGATOR_H_

#include <SPL/Runtime/Common/Metric.h>
#include <SPL/Runtime/Operator/Operator.h>
#include <SPL/Runtime/Operator/ParameterValue.h>
#include <SPL/Runtime/Operator/OperatorContext.h>
#include <SPL/Runtime/Operator/OperatorMetrics.h>
#include <SPL/Runtime/Operator/Port/AutoPortMutex.h>
#include <SPL/Runtime/Operator/State/StateHandler.h>
#include <SPL/Runtime/ProcessingElement/PE.h>
#include <SPL/Runtime/Type/SPLType.h>
#include <SPL/Runtime/Window/Window.h>
#include <SPL/Runtime/Utility/CV.h>
using namespace UTILS_NAMESPACE;

#include "../type/BeJwrMcm0zM3MC0otLs0pATITK2DMxLJ0GLO4NBfCBAClbRJK.h"
#include "../type/BeJwrMco0rMg0K0otLs0pAQAgzAT3.h"

#include <bitset>

#define MY_OPERATOR ResultAggregator$OP
#define MY_BASE_OPERATOR ResultAggregator_Base
#define MY_OPERATOR_SCOPE SPL::_Operator

namespace SPL {
namespace _Operator {

class MY_BASE_OPERATOR : public Operator
{
public:
    
    typedef SPL::BeJwrMco0rMg0K0otLs0pAQAgzAT3 IPort0Type;
    typedef SPL::BeJwrMcm0zM3MC0otLs0pATITK2DMxLJ0GLO4NBfCBAClbRJK OPort0Type;
    
    MY_BASE_OPERATOR();
    
    ~MY_BASE_OPERATOR();
    
    inline void tupleLogic(Tuple const & tuple, uint32_t port);
    void processRaw(Tuple const & tuple, uint32_t port);
    
    inline void punctLogic(Punctuation const & punct, uint32_t port);
    void processRaw(Punctuation const & punct, uint32_t port);
    void punctPermitProcessRaw(Punctuation const & punct, uint32_t port);
    void punctNoPermitProcessRaw(Punctuation const & punct, uint32_t port);
    
    inline void submit(Tuple & tuple, uint32_t port)
    {
        Operator::submit(tuple, port);
    }
    inline void submit(Punctuation const & punct, uint32_t port)
    {
        Operator::submit(punct, port);
    }
    
    
    
    SPL::int32 lit$0;
    
    
protected:
    Mutex $svMutex;
    typedef std::bitset<2> OPortBitsetType;
    OPortBitsetType $oportBitset;
    Mutex $fpMutex;
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
 

class MY_OPERATOR : public MY_BASE_OPERATOR, 
                    public SPL::WindowEvent<SPL::BeJwrMco0rMg0K0otLs0pAQAgzAT3>,
                    public StateHandler
{
public:
    typedef int32_t GroupByType; 
    
    
    
    typedef int32_t PartitionByType; 
    typedef SPL::TumblingWindow<IPort0Type> WindowType;
    typedef SPL::WindowEvent<IPort0Type> WindowEventType;
    MY_OPERATOR();
    ~MY_OPERATOR();
    void process(Tuple const & tuple, uint32_t port); 


    void beforeWindowFlushEvent(WindowEventType::WindowType & window, 
                                WindowEventType::PartitionType const & partition);



    struct Tumbling$ResultAggregator;

    // StateHandler implementation
    void drain();
    void checkpoint(Checkpoint & ckpt);
    void reset(Checkpoint & ckpt);
    void resetToInitialState();

private:
    void aggregatePartition(WindowEventType::WindowType & window, 
                            WindowEventType::PartitionType const & partition);

    WindowType _window;
    Mutex    _mutex;

    Metric& _partitionCount;
    
}; 
 
} // namespace _Operator
} // namespace SPL

#undef MY_OPERATOR_SCOPE
#undef MY_BASE_OPERATOR
#undef MY_OPERATOR
#endif // SPL_OPER_INSTANCE_RESULTAGGREGATOR_H_

