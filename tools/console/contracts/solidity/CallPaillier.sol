// CallPaillier.sol
pragma solidity ^0.4.24;
import "./PaillierPrecompiled.sol";

contract CallPaillier {
    PaillierPrecompiled paillier;
    function CallPaillier() {
        // 调用PaillierPrecompiled预编译合约
        paillier = PaillierPrecompiled(0x5003);
    }
    function enc(string cipher1, string cipher2) public returns(string) {
        return paillier.paillierAdd(cipher1, cipher2);
    }
}