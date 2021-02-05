// CallPaillier.sol
pragma solidity ^0.4.24;
import "./PaillierPrecompiled.sol";

contract CallPaillier5times {
    PaillierPrecompiled paillier;
    function CallPaillier5times() {
        // 调用PaillierPrecompiled预编译合约
        paillier = PaillierPrecompiled(0x5003);
    }

    function enc(string cipher1, string cipher2) public returns(string) {
        for (uint i = 0; i < 5; i++){
            paillier.paillierAdd(cipher1, cipher2);
        }
        return paillier.paillierAdd(cipher1, cipher2);
    }
}