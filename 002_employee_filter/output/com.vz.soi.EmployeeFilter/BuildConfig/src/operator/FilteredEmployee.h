// eJytUUFOwzAQ1P4kqlCVXGIn4oAieoACh6pFldweeoqMuk2tOnZwDG14PY5DCw0SCAn5NLuzO7PjupKxQcmt0IrLLHsQ0qKBBKh7CQzimNimQnKLk72ZsV3aLF9ni82yWewO8_0liZRv2NmGMpozmySOjO3tTjJfj_1fNdvB24FSlIYS8osPk0y16EslfgK0lXMbU1QhUAQLa6ROIg8rLm61IoUmtBKE1zLCupG8R8482RNbcclFbYOtwcDft9T1pL5MrBMBSVNk46LtDmBao1mjAKRqPAy0fBcBicUXiBrn_1d9WkUwf2hMljXLhgfxwe30_1l7HCDA_0FABLkHxEuF4uxOGLhkrrPysd55PsPWg_18FDTz2B3lecLvWptNww_0uLxxO_1gOdtn2DvjFwFPdkPfrv1x6vifLpR3U6DbA2




#ifndef SPL_OPER_INSTANCE_FILTEREDEMPLOYEE_H_
#define SPL_OPER_INSTANCE_FILTEREDEMPLOYEE_H_

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

#include <bitset>

#define MY_OPERATOR FilteredEmployee$OP
#define MY_BASE_OPERATOR FilteredEmployee_Base
#define MY_OPERATOR_SCOPE SPL::_Operator

namespace SPL {
namespace _Operator {

class MY_BASE_OPERATOR : public Operator
{
public:
    
    typedef SPL::BeJwrMSk2yUvMTfUyTkxPLTYtySzJSS02S0_1NS0ktAgCUCwqD IPort0Type;
    typedef SPL::BeJwrMSk2yUvMTfUyTkxPLTYtySzJSS02S0_1NS0ktAgCUCwqD OPort0Type;
    
    MY_BASE_OPERATOR();
    
    ~MY_BASE_OPERATOR();
    
    inline void tupleLogic(Tuple const & tuple, uint32_t port);
    void processRaw(Tuple const & tuple, uint32_t port);
    
    inline void punctLogic(Punctuation const & punct, uint32_t port);
    void processRaw(Punctuation const & punct, uint32_t port);
    void punctPermitProcessRaw(Punctuation const & punct, uint32_t port);
    void punctNoPermitProcessRaw(Punctuation const & punct, uint32_t port);
    
    
    
    SPL::uint8 lit$0;
    SPL::rstring lit$1;
    
    
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
#endif // SPL_OPER_INSTANCE_FILTEREDEMPLOYEE_H_

