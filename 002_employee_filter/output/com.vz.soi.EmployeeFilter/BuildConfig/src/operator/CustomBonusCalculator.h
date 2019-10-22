// eJydVNFumzAUlV_17FVZVVTBV4JCkq0gzKcueqjTKRPLQJ_0QGh3oBzLBZS6f_0_04ydxKTQTi1ICA4_09557rq95njiloAkVle9PSy5YCnoAydsDp47jiion7ndy81jcBsirVn9ul5tVtdw_0LWbLO1EFzzeBxAMU9uYB2or1r_1m84lfF7OfdZPi8nk9S5_0G0FWj7_10CTeLqaPv7_0UdMR_0AqkwDMEgsXM9wsuCprFQGE9jW0ShsXlQGOexkqaiSuN9DuYgw7msAO7NNH6HgDAfWApcWUkglOOo5RmLmfURcgLSZonrCIk3NBEkMKNsMAgYxmp_1axdpTkrDnV83AyQgkL15u8JlFczyqd6A2l0xpZlnpCReXXWCcGFZY9UDp2pvsyCmIgwJllE5Co4hruijuDRG7QMp6RF0uBbFEFF0ubsUEMyLbeO_0ThusxXWIPu_0omPOaZwtcCX7H5kwF3vujvGinnQDLaurdjgeQ7VdbRseMhgf2xXes6zkSqPa0UaWTkQSTow3ddZ30_1ZteH4OrVa58Fr_19_0ymrra29_1RZO6N4noRrzMV1c1wuGj2A33y_1XtCWYcMvSsagYb_0ptVXvx_1SpGe6Ky8v7lArY7KmabSni5QSAAaj3INifD1Io0KeH2mYHXFt9_0KwnmnVM9KdmUc328FgHaihBr7Sg12oQUD6A_1eGFpLx_1aAm0Cp


#ifndef SPL_OPER_INSTANCE_CUSTOMBONUSCALCULATOR_H_
#define SPL_OPER_INSTANCE_CUSTOMBONUSCALCULATOR_H_

#include <SPL/Runtime/Serialization/NetworkByteBuffer.h>
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

#define MY_OPERATOR CustomBonusCalculator$OP
#define MY_BASE_OPERATOR CustomBonusCalculator_Base
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
    
    inline void tupleLogic(Tuple & tuple, uint32_t port);
    void processRaw(Tuple & tuple, uint32_t port);
    
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
    
    
    
    SPL::rstring lit$0;
    SPL::float64 lit$1;
    SPL::uint8 lit$2;
    SPL::rstring lit$3;
    SPL::float64 lit$4;
    SPL::float64 lit$5;
    SPL::uint32 lit$6;
    
    
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
   
   
}; 

} // namespace _Operator
} // namespace SPL

#undef MY_OPERATOR_SCOPE
#undef MY_BASE_OPERATOR
#undef MY_OPERATOR
#endif // SPL_OPER_INSTANCE_CUSTOMBONUSCALCULATOR_H_

