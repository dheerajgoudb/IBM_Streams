// eJydUk1PwzAMlf9JhRBqEWqzwhCqAGl8HdCYhrodOFVh80pYmpQkA8qvJ0vYxhgCgXLy83P8_1Gxd81ghp4ZJQXmWXc3EyEgFLSD2pbAVx4lpakzO8PpF3eQkbYbPN4PJsBlMX_1vdwZ1p8rfr3OI5KVq9nEzN6LHXa_1SR6t7eddpvo16nih_02Nj6a_1v5Rpzwfnr88XczLCewDZ2abQN7vZtmMCXMEDml5RGmjmCg9lnpswiU1hwcAkDzIChNLQVppOq6YSLRkCSFpgVXNZYNYTBg3qJIxNRSEFEisCR6Djx73UnKkwoZhyGqprJy4RFOUKMaowig4OQmcpCjY2QnWKLREmz_11eRJFcPlaK9Ta2u68_1uD6Pn_03CBgotzGAAxC0Qlj4YRuDd8sww1e417wM5xrkNxr_0tW_0orJr2uo4WfFnUcmbnz5wbRp_1ULvk_0XGc7N78M9EsDR7ZFG3P_1WLXYLNxLMdOwOKhl1QoIs8whuubFiGpz_1Dm_1F6xGCU6zbE7YPI8o2HXnkUZ2G_099QB2W



#ifndef SPL_OPER_INSTANCE_EMPLOYEEWITHBONUS_H_
#define SPL_OPER_INSTANCE_EMPLOYEEWITHBONUS_H_

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

#include "../type/BeJwrMS02yUvMTfUyTkxPLTYtySzJSS02S0_1NS0ktcjNNys8rLQYA5zcNAm.h"
#include "../type/BeJwrMSk2yUvMTfUyTkxPLTYtySzJSS02S0_1NS0ktAgCUCwqD.h"

#include <bitset>

#define MY_OPERATOR EmployeeWithBonus$OP
#define MY_BASE_OPERATOR EmployeeWithBonus_Base
#define MY_OPERATOR_SCOPE SPL::_Operator

namespace SPL {
namespace _Operator {

class MY_BASE_OPERATOR : public Operator
{
public:
    
    typedef SPL::BeJwrMSk2yUvMTfUyTkxPLTYtySzJSS02S0_1NS0ktAgCUCwqD IPort0Type;
    typedef SPL::BeJwrMS02yUvMTfUyTkxPLTYtySzJSS02S0_1NS0ktcjNNys8rLQYA5zcNAm OPort0Type;
    
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
    
    
    
    SPL::uint8 lit$0;
    SPL::rstring lit$1;
    SPL::float64 lit$2;
    
    
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


class MY_OPERATOR : public MY_BASE_OPERATOR
{
public:
   MY_OPERATOR() {}
  
   void process(Tuple const & tuple, uint32_t port);
   void process(Punctuation const & punct, uint32_t port);
   
}; 

} // namespace _Operator
} // namespace SPL

#undef MY_OPERATOR_SCOPE
#undef MY_BASE_OPERATOR
#undef MY_OPERATOR
#endif // SPL_OPER_INSTANCE_EMPLOYEEWITHBONUS_H_

