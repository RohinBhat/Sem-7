pragma solidity ^0.8.0;

// SPDX-License-Identifier: UNLICENSED

contract Bank {
    uint256 balance;

    function deposit(uint256 amt) public returns (uint256) {
        balance += amt;
        return 1;
    }

    function withdraw(uint256 amt) public returns (uint256) {
        if (amt > balance) {
            return 0;
        }
        balance -= amt;
        return 1;
    }

    function showBalance() public view returns (uint256) {
        return balance;
    }
}
