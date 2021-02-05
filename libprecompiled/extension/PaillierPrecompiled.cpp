/*
 * @CopyRight:
 * FISCO-BCOS is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * FISCO-BCOS is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with FISCO-BCOS.  If not, see <http://www.gnu.org/licenses/>
 * (c) 2016-2018 fisco-dev contributors.
 */
/** @file PaillierPrecompiled.h
 *  @author shawnhe
 *  @date 20190808
 */

#include "PaillierPrecompiled.h"
#include <libdevcore/Common.h>
#include <libethcore/ABI.h>
#include <paillier/callpaillier.h>
#include <string>
// #include <NTL/ZZ.h>
// #include <NTL/ZZ_pXFactoring.h>
// #include <sstream>

using namespace dev;
using namespace dev::blockverifier;
using namespace dev::precompiled;
const char* const PAILLIER_METHOD_SET_STR = "paillierAdd(string,string)";
// const char* const PAILLIER_METHOD_SET_STR = "paillierEnc(string, string, string, string)";

PaillierPrecompiled::PaillierPrecompiled() : m_callPaillier(std::make_shared<CallPaillier>())
{
    name2Selector[PAILLIER_METHOD_SET_STR] = getFuncSelector(PAILLIER_METHOD_SET_STR);
    // name2Selector[PAILLIER_METHOD_SET] = getFuncSelector(PAILLIER_METHOD_SET);
}

// NTL::ZZ PaillierPrecompiled::PaillierPrecompiled::paillierEnc(const NTL::ZZ& message, const NTL::ZZ& random, const NTL::ZZ& generator, const NTL::ZZ& modulus) {
//     NTL::ZZ ciphertext =
//         NTL::PowerMod(generator, message, modulus * modulus) *
//         NTL::PowerMod(random, modulus, modulus * modulus);
//     return ciphertext % (modulus * modulus);
// }

// std::string PaillierPrecompiled::PaillierPrecompiled::paillierEnc(std::string& message, std::string& random, std::string& generator, std::string& modulus)
// {
//     NTL::ZZ message_zz = NTL::conv<NTL::ZZ>( message.c_str());
//     NTL::ZZ random_zz = NTL::conv<NTL::ZZ>(random.c_str());
//     NTL::ZZ generator_zz = NTL::conv<NTL::ZZ>(generator.c_str());
//     NTL::ZZ modulus_zz = NTL::conv<NTL::ZZ>(modulus.c_str());
//     NTL::ZZ result = paillierEnc(message_zz, random_zz, generator_zz, modulus_zz);
//     std::stringstream buffer;
//     buffer << result;
//     return buffer.str();
// }

PrecompiledExecResult::Ptr PaillierPrecompiled::call(
    ExecutiveContext::Ptr, bytesConstRef param, Address const&, Address const&)
{
    PRECOMPILED_LOG(TRACE) << LOG_BADGE("PaillierPrecompiled") << LOG_DESC("call")
                           << LOG_KV("param", toHex(param));

    // parse function name
    uint32_t func = getParamFunc(param);
    bytesConstRef data = getParamData(param);

    dev::eth::ContractABI abi;
    auto callResult = m_precompiledExecResultFactory->createPrecompiledResult();
    callResult->gasPricer()->setMemUsed(param.size());
    if (func == name2Selector[PAILLIER_METHOD_SET_STR])
    {
        // paillierAdd(string,string)
        std::string cipher1, cipher2;
        abi.abiOut(data, cipher1, cipher2);
        std::string result;
        try
        {
            std::string generator = "10";
            std::string modulus = "65537";
            result = m_callPaillier->paillierEnc(generator, modulus, cipher1, cipher2);
            callResult->gasPricer()->appendOperation(InterfaceOpcode::PaillierAdd);
        }
        catch (CallException& e)
        {
            PRECOMPILED_LOG(ERROR)
                << LOG_BADGE("PaillierPrecompiled") << LOG_DESC(std::string(e.what()))
                << LOG_KV("cipher1", cipher1) << LOG_KV("cipher2", cipher2);
            getErrorCodeOut(callResult->mutableExecResult(), CODE_INVALID_CIPHERS);
            return callResult;
        }
        callResult->setExecResult(abi.abiIn("", result));
    }
    // if (func == name2Selector[PAILLIER_METHOD_SET_STR])
    // {
    //     std::string cipher;
    //     std::string random;
    //     std::string generator;
    //     std::string modulus;
    //     abi.abiOut(data, cipher, random, generator, modulus);
    //     std::string result1;
    //     try
    //     {
    //         result1 = m_callPaillier->paillierEnc(cipher, random, generator, modulus);
    //         callResult->gasPricer()->appendOperation(InterfaceOpcode::PaillierEnc);
    //     }
    //     catch (CallException& e)
    //     {
    //         PRECOMPILED_LOG(ERROR)
    //             << LOG_BADGE("PaillierPrecompiled") << LOG_DESC(std::string(e.what()))
    //             << LOG_KV("cipher", cipher) << LOG_KV("random", random) << LOG_KV("generator", generator) << LOG_KV("modulus", modulus);
    //         getErrorCodeOut(callResult->mutableExecResult(), CODE_INVALID_CIPHERS);
    //         return callResult;
    //     }
    //     callResult->setExecResult(abi.abiIn("", result1));
    // }
    else
    {
        PRECOMPILED_LOG(ERROR) << LOG_BADGE("PaillierPrecompiled")
                               << LOG_DESC("call undefined function") << LOG_KV("func", func);
        getErrorCodeOut(callResult->mutableExecResult(), CODE_UNKNOW_FUNCTION_CALL);
    }
    return callResult;
}
