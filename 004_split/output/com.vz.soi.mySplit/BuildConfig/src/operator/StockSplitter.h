// eJzl0j1vwjAQBmDdX0EdYMk3ELJR1A7QqLTJjhI4wMKJXduozb_0vCQ5S2g6tOloeIlv33uWxLDl1zopQopokybj_0gg_0eXj4MHMdVDUf3HpfvIs2iYDWZpvlWrLM8VauUp_1kpaPLFm5ot4lUuw_0X8ZVGWc_1HqHAdtB93tzoNs_1ZQkQipB6gMAuEdWoau3WFSy2FWkdiUjrudFG3mZ7_04KVUDNavQggD2hqDv1enSN50rvy7PCR4EIJ2y_0FnpAOBO61Dmg2simKhkdjuDhgwuUkrC6tZqaa_1TPViAg2gsDCOE6Arr5XJAtwp6yQoUBlOfmWWRIKZSMUSz09EuO_1X_18t8H_0L2_0i_14O3VHfQT7XFOvSDowt2B_13gLTAc_0e27uJJ9e8iBIQf2kENDDu0hR4Yc2UMeG_1LYHvLEkCf2kKeGPLWHHBtybA95Zsgza8if4OthCb



#ifndef SPL_OPER_INSTANCE_STOCKSPLITTER_H_
#define SPL_OPER_INSTANCE_STOCKSPLITTER_H_

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

#include <bitset>
#include <vector>

#define MY_OPERATOR StockSplitter$OP
#define MY_BASE_OPERATOR StockSplitter_Base
#define MY_OPERATOR_SCOPE SPL::_Operator

namespace SPL {
namespace _Operator {

class MY_BASE_OPERATOR : public Operator
{
public:
    
    typedef SPL::BeJwrMS42K67MTcrPSTMtKMpMTk2yTCqt9C8KTs3JAQCbbArR IPort0Type;
    typedef SPL::BeJwrMS42K67MTcrPSTMtKMpMTk2yTCqt9C8KTs3JAQCbbArR OPort0Type;
    typedef SPL::BeJwrMS42K67MTcrPSTMtKMpMTk2yTCqt9C8KTs3JAQCbbArR OPort1Type;
    typedef SPL::BeJwrMS42K67MTcrPSTMtKMpMTk2yTCqt9C8KTs3JAQCbbArR OPort2Type;
    typedef SPL::BeJwrMS42K67MTcrPSTMtKMpMTk2yTCqt9C8KTs3JAQCbbArR OPort3Type;
    typedef SPL::BeJwrMS42K67MTcrPSTMtKMpMTk2yTCqt9C8KTs3JAQCbbArR OPort4Type;
    typedef SPL::BeJwrMS42K67MTcrPSTMtKMpMTk2yTCqt9C8KTs3JAQCbbArR OPort5Type;
    typedef SPL::BeJwrMS42K67MTcrPSTMtKMpMTk2yTCqt9C8KTs3JAQCbbArR OPort6Type;
    typedef SPL::BeJwrMS42K67MTcrPSTMtKMpMTk2yTCqt9C8KTs3JAQCbbArR OPort7Type;
    typedef SPL::BeJwrMS42K67MTcrPSTMtKMpMTk2yTCqt9C8KTs3JAQCbbArR OPort8Type;
    typedef SPL::BeJwrMS42K67MTcrPSTMtKMpMTk2yTCqt9C8KTs3JAQCbbArR OPort9Type;
    
    MY_BASE_OPERATOR();
    
    ~MY_BASE_OPERATOR();
    
    inline void tupleLogic(Tuple const & tuple, uint32_t port);
    void processRaw(Tuple const & tuple, uint32_t port);
    
    inline void punctLogic(Punctuation const & punct, uint32_t port);
    void processRaw(Punctuation const & punct, uint32_t port);
    void punctPermitProcessRaw(Punctuation const & punct, uint32_t port);
    void punctNoPermitProcessRaw(Punctuation const & punct, uint32_t port);
    
    
    
    SPL::rstring lit$0;
    
    
protected:
    Mutex $svMutex;
    typedef std::bitset<2> OPortBitsetType;
    std::vector<OPortBitsetType> $oportBitset;
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
    MY_OPERATOR();

    virtual void process(Tuple const & tuple, uint32_t port);
    virtual void process(Punctuation const & punct, uint32_t port);

private:
    typedef std::tr1::unordered_map<SPL::rstring, std::vector<int64_t> > MapType;
    MapType _Map;
    std::vector<int64_t> _Default;
    bool _hasDefault;
    std::string _fileName;

}; 

} // namespace _Operator
} // namespace SPL

#undef MY_OPERATOR_SCOPE
#undef MY_BASE_OPERATOR
#undef MY_OPERATOR
#endif // SPL_OPER_INSTANCE_STOCKSPLITTER_H_

