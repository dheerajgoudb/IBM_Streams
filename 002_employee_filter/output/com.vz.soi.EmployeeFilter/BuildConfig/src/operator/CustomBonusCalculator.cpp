// eJydVNFumzAUlV_17FVZVVTBV4JCkq0gzKcueqjTKRPLQJ_0QGh3oBzLBZS6f_0_04ydxKTQTi1ICA4_09557rq95njiloAkVle9PSy5YCnoAydsDp47jiion7ndy81jcBsirVn9ul5tVtdw_0LWbLO1EFzzeBxAMU9uYB2or1r_1m84lfF7OfdZPi8nk9S5_0G0FWj7_10CTeLqaPv7_0UdMR_0AqkwDMEgsXM9wsuCprFQGE9jW0ShsXlQGOexkqaiSuN9DuYgw7msAO7NNH6HgDAfWApcWUkglOOo5RmLmfURcgLSZonrCIk3NBEkMKNsMAgYxmp_1axdpTkrDnV83AyQgkL15u8JlFczyqd6A2l0xpZlnpCReXXWCcGFZY9UDp2pvsyCmIgwJllE5Co4hruijuDRG7QMp6RF0uBbFEFF0ubsUEMyLbeO_0ThusxXWIPu_0omPOaZwtcCX7H5kwF3vujvGinnQDLaurdjgeQ7VdbRseMhgf2xXes6zkSqPa0UaWTkQSTow3ddZ30_1ZteH4OrVa58Fr_19_0ymrra29_1RZO6N4noRrzMV1c1wuGj2A33y_1XtCWYcMvSsagYb_0ptVXvx_1SpGe6Ky8v7lArY7KmabSni5QSAAaj3INifD1Io0KeH2mYHXFt9_0KwnmnVM9KdmUc328FgHaihBr7Sg12oQUD6A_1eGFpLx_1aAm0Cp


#include "./CustomBonusCalculator.h"
using namespace SPL::_Operator;

#include <SPL/Runtime/Function/SPLFunctions.h>
#include <SPL/Runtime/Operator/Port/Punctuation.h>

#include <string>

#define MY_OPERATOR_SCOPE SPL::_Operator
#define MY_BASE_OPERATOR CustomBonusCalculator_Base
#define MY_OPERATOR CustomBonusCalculator$OP



static SPL::Operator * initer() { return new MY_OPERATOR_SCOPE::MY_OPERATOR(); }
bool MY_BASE_OPERATOR::globalInit_ = MY_BASE_OPERATOR::globalIniter();
bool MY_BASE_OPERATOR::globalIniter() {
    instantiators_.insert(std::make_pair("CustomBonusCalculator",&initer));
    return true;
}

template<class T> static void initRTC (SPL::Operator& o, T& v, const char * n) {
    SPL::ValueHandle vh = v;
    o.getContext().getRuntimeConstantValue(vh, n);
}

MY_BASE_OPERATOR::MY_BASE_OPERATOR()
 : Operator() {
    uint32_t index = getIndex();
    initRTC(*this, lit$0, "lit$0");
    initRTC(*this, lit$1, "lit$1");
    initRTC(*this, lit$2, "lit$2");
    initRTC(*this, lit$3, "lit$3");
    initRTC(*this, lit$4, "lit$4");
    initRTC(*this, lit$5, "lit$5");
    initRTC(*this, lit$6, "lit$6");
    (void) getParameters(); // ensure thread safety by initializing here
    $oportBitset = OPortBitsetType(std::string("01"));
}
MY_BASE_OPERATOR::~MY_BASE_OPERATOR()
{
    for (ParameterMapType::const_iterator it = paramValues_.begin(); it != paramValues_.end(); it++) {
        const ParameterValueListType& pvl = it->second;
        for (ParameterValueListType::const_iterator it2 = pvl.begin(); it2 != pvl.end(); it2++) {
            delete *it2;
        }
    }
}

void MY_BASE_OPERATOR::tupleLogic(Tuple & tuple, uint32_t port) {
    IPort0Type & iport$0 = static_cast<IPort0Type  &>(tuple);
    AutoPortMutex $apm($svMutex, *this);
    
{
    SPL::BeJwrMS02yUvMTfUyTkxPLTYtySzJSS02S0_1NS0ktcjNNys8rLQYA5zcNAm id$oTuple; id$oTuple.clear();
    {
        id$oTuple.get_gender() = iport$0.get_gender();
        id$oTuple.get_name() = iport$0.get_name();
        id$oTuple.get_title() = iport$0.get_title();
        SPL::uint8(id$oTuple.get_age() = iport$0.get_age());
        ::SPL::assignPayload(id$oTuple, iport$0);
    }
    if ((iport$0.get_gender() == lit$0)) 
        {
            id$oTuple.get_bonus() = lit$1;
        }
    else
        if (((iport$0.get_gender() == lit$3) && (iport$0.get_age() <= lit$2))) 
            {
                id$oTuple.get_bonus() = (::SPL::spl_cast<SPL::float64, SPL::uint8 >::cast(iport$0.get_age()) * lit$4);
            }
        else
            {
                id$oTuple.get_bonus() = lit$5;
            }
    submit (id$oTuple, lit$6);
}

}


void MY_BASE_OPERATOR::processRaw(Tuple & tuple, uint32_t port) {
    tupleLogic (tuple, port);
    static_cast<MY_OPERATOR_SCOPE::MY_OPERATOR*>(this)->MY_OPERATOR::process(tuple, port);
}


void MY_BASE_OPERATOR::punctLogic(Punctuation const & punct, uint32_t port) {
}

void MY_BASE_OPERATOR::punctPermitProcessRaw(Punctuation const & punct, uint32_t port) {
    {
        punctNoPermitProcessRaw(punct, port);
    }
}

void MY_BASE_OPERATOR::punctNoPermitProcessRaw(Punctuation const & punct, uint32_t port) {
    switch(punct) {
    case Punctuation::WindowMarker:
        punctLogic(punct, port);
        process(punct, port);
        break;
    case Punctuation::FinalMarker:
        punctLogic(punct, port);
        
        if (punct == Punctuation::FinalMarker) {
            process(punct, port);
            bool forward = false;
            {
                AutoPortMutex $apm($fpMutex, *this);
                $oportBitset.reset(port);
                if ($oportBitset.none()) {
                    $oportBitset.set(1);
                    forward=true;
                }
            }
            if(forward)
                submit(punct, 0);
            return;
        }
        process(punct, port);
        break;
    case Punctuation::DrainMarker:
    case Punctuation::ResetMarker:
    case Punctuation::ResumeMarker:
        break;
    case Punctuation::SwitchMarker:
        break;
    default:
        break;
    }
}

void MY_BASE_OPERATOR::processRaw(Punctuation const & punct, uint32_t port) {
    switch(port) {
    case 0:
        punctNoPermitProcessRaw(punct, port);
        break;
    }
}



void MY_BASE_OPERATOR::checkpointStateVariables(NetworkByteBuffer & opstate) const {
}

void MY_BASE_OPERATOR::restoreStateVariables(NetworkByteBuffer & opstate) {
}

void MY_BASE_OPERATOR::checkpointStateVariables(Checkpoint & ckpt) {
}

void MY_BASE_OPERATOR::resetStateVariables(Checkpoint & ckpt) {
}

void MY_BASE_OPERATOR::resetStateVariablesToInitialState() {
}

bool MY_BASE_OPERATOR::hasStateVariables() const {
    return false;
}

void MY_BASE_OPERATOR::resetToInitialStateRaw() {
    AutoMutex $apm($svMutex);
    StateHandler *sh = getContext().getStateHandler();
    if (sh != NULL) {
        sh->resetToInitialState();
    }
    resetStateVariablesToInitialState();
}

void MY_BASE_OPERATOR::checkpointRaw(Checkpoint & ckpt) {
    AutoMutex $apm($svMutex);
    StateHandler *sh = getContext().getStateHandler();
    if (sh != NULL) {
        sh->checkpoint(ckpt);
    }
    checkpointStateVariables(ckpt);
}

void MY_BASE_OPERATOR::resetRaw(Checkpoint & ckpt) {
    AutoMutex $apm($svMutex);
    StateHandler *sh = getContext().getStateHandler();
    if (sh != NULL) {
        sh->reset(ckpt);
    }
    resetStateVariables(ckpt);
}



