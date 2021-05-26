English / [中文](docs/README_CN.md)

![](docs/images/FISCO_BCOS_Logo.svg)

## Usage

This project implements a fair transaction protocol for cloud/fog computing based on FISCO BCOS.

The next paragraph describes how to run the code.

1. Download the source code

   ```shell
   git clone https://github.com/wwe1428103707/FairTransactionForOutsourcingComputationUsingBlockchain.git
   ```

2. Download the important library from the following link

   ```shell
   https://github.com/wwe1428103707/FairTransactionForOutsourcingComputationUsingBlockchain/releases/download/lib/libpaillier.a
   ```
   
3. ```shell
   cd FairTransactionForOutsourcingComputationUsingBlockchain/
   ```

4. ```shell
   sudo apt install -y g++ libssl-dev openssl cmake git build-essential autoconf texinfo flex patch bison libgmp-dev zlib1g-dev
   ```

   

5. ```shell
   mkdir -p build && cd build
   cmake ..
   sudo make
   ```
   
6. Replace all libpaillier. A files with the file linked below

7. [Release important lib · wwe1428103707/FairTransactionForOutsourcingComputationUsingBlockchain (github.com)](https://github.com/wwe1428103707/FairTransactionForOutsourcingComputationUsingBlockchain/releases/tag/lib)

8. ```shell
   sudo make
   ```
   again.

9. start fisco-bcos

   ```shell
   sudo apt install -y openssl curl
   cd ../tools/
   sudo bash build_chain.sh -l 127.0.0.1:4 -p 30300,20200,8545
   sudo bash nodes/127.0.0.1/start_all.sh
   ```

10. Success will output a response similar to the following, otherwise, please use `netstat -an | grep tcp` to check whether the machine’s `30300~30303, 20200~20203, 8545~8548` ports are occupied.

    ```shell
    try to start node0
    try to start node1
    try to start node2
    try to start node3
     node1 start successfully
     node2 start successfully
     node0 start successfully
     node3 start successfully
    ```

11. Execute the following command to check whether the process is started

    ```
    ps -ef | grep -v grep | grep fisco-bcos
    ```

    In normal situation, the output will be similar to the following. If the number of processes is not 4, then the reason why the process does not start is that the port is occupied.

    ```shell
    fisco       5453     1  1 17:11 pts/0    00:00:02 /home/ubuntu/fisco/nodes/127.0.0.1/node0/../fisco-bcos -c config.ini
    fisco       5459     1  1 17:11 pts/0    00:00:02 /home/ubuntu/fisco/nodes/127.0.0.1/node1/../fisco-bcos -c config.ini
    fisco       5464     1  1 17:11 pts/0    00:00:02 /home/ubuntu/fisco/nodes/127.0.0.1/node2/../fisco-bcos -c config.ini
    fisco       5476     1  1 17:11 pts/0    00:00:02 /home/ubuntu/fisco/nodes/127.0.0.1/node3/../fisco-bcos -c config.ini
    ```

12. Execute the following command to view the number of nodes that node0 links to

    ```shell
    tail -f nodes/127.0.0.1/node0/log/log*  | grep connected
    ```

    In normal situation, the connecting messages will be output continuously. From the output messages, we can see that node0 has links with the other three nodes.

    ```shell
    info|2019-01-21 17:30:58.316769| [P2P][Service] heartBeat,connected count=3
    info|2019-01-21 17:31:08.316922| [P2P][Service] heartBeat,connected count=3
    info|2019-01-21 17:31:18.317105| [P2P][Service] heartBeat,connected count=3
    ```

13. using console

    ```shell
    sudo apt install -y default-jdk
    ```

    Java version recommendation 14.

14. ```
    cp -r nodes/127.0.0.1/sdk/* console/conf/
    ```

15. ```
    bash console/start.sh
    ```

Then, you can start using the FISCO-BCOS console. Refer to the following links for detailed documentation. English version: [Console — FISCO BCOS EN v2.6.0 documentation (fisco-bcos-documentation.readthedocs.io)](https://fisco-bcos-documentation.readthedocs.io/en/latest/docs/console/index.html) Chinese version: [命令行交互控制台 — FISCO BCOS v2.7.2 文档 (fisco-bcos-documentation.readthedocs.io)](https://fisco-bcos-documentation.readthedocs.io/zh_CN/latest/docs/console/index.html)

16. After building the chain by the newly compiled binary, deploy the console (version v1.0.2 or later), and copy the interface declaration files to the console contract directory. Take calling homomorphic encryption as **call** command. Please refer to the following link for details [Privacy protection — FISCO BCOS EN v2.6.0 documentation (fisco-bcos-documentation.readthedocs.io)](https://fisco-bcos-documentation.readthedocs.io/en/latest/docs/manual/privacy.html)

If you have any questions, please contact me at **yufaji@std.uest.edu.cn** and **yufangjianFISH@163.com**.

*The following is the official readme file of the original FISCO BCOS.*

**FISCO BCOS** is a secure and reliable financial-grade open-source blockchain platform led by Chinese enterprises. Its performance has reached over 10,000 TPS with single-chain setup. The platform provides rich features including group architecture, cross-chain communication protocols, pluggable consensus mechanisms, privacy protection algorithms, OSCCA-approved (Office of State Commercial Cryptography Administration) cryptography algorithms, and distributed storage. Its performance, usability, and security have been testified by many institutional users and successful business applications in a live production environment.

[![codecov](https://codecov.io/gh/FISCO-BCOS/FISCO-BCOS/branch/master/graph/badge.svg)](https://codecov.io/gh/FISCO-BCOS/FISCO-BCOS) [![CodeFactor](https://www.codefactor.io/repository/github/fisco-bcos/FISCO-BCOS/badge)](https://www.codefactor.io/repository/github/fisco-bcos/FISCO-BCOS) [![Codacy Badge](https://api.codacy.com/project/badge/Grade/08552871ee104fe299b00bc79f8a12b9)](https://www.codacy.com/app/fisco-dev/FISCO-BCOS?utm_source=github.com&amp;utm_medium=referral&amp;utm_content=FISCO-BCOS/FISCO-BCOS&amp;utm_campaign=Badge_Grade) [![GitHub All Releases](https://img.shields.io/github/downloads/FISCO-BCOS/FISCO-BCOS/total.svg)](https://github.com/FISCO-BCOS/FISCO-BCOS) [![Code Lines](https://tokei.rs/b1/github/FISCO-BCOS/FISCO-BCOS?category=code)](https://github.com/FISCO-BCOS/FISCO-BCOS)

[![CircleCI](https://circleci.com/gh/FISCO-BCOS/FISCO-BCOS.svg?style=shield)](https://circleci.com/gh/FISCO-BCOS/FISCO-BCOS)  [![Build Status](https://travis-ci.org/FISCO-BCOS/FISCO-BCOS.svg)](https://travis-ci.org/FISCO-BCOS/FISCO-BCOS)

## Group Architecture

Our group architecture is designed to allow the simultaneous management of multiple ledger groups in the same blockchain network to facilitate speedy ledger setup and support massive service requests. This innovative architecture supports better scalability with key designs including inter-group transaction processing, distributed data storage, and intra-group consensus isolation. It aims to effectively scale up the business and simplify toilsome operational procedures while accommodating to data privacy protection requirements.

## Distributed Storage

Distributed storage framework aims to break the limitations of single-machine resource and boost system capacity and performance. It separates computation and storage units with modularized data exchange API for better flexibility. This framework simplifies data management and accelerate business development flow by defining standard CURD adaptors for common databases like MySQL, and supporting widely-used Key-Value and SQL-like data tables.

## Parallel Transaction Processing

Parallel transaction processing engine effectively exploits multi-core computation resources to parallelize transaction processing. To address key performance bottleneck caused high frequency and high complexity computation, it provides pre-compiled framework to run C++-based smart contracts, which significantly boosts the efficiency of transaction execution.

## Developer Friendly

FISCO BCOS provides various guides to compile and deploy blockchain instances, offering one-click deployment, speedy installation, and deployment on all mainstream platforms including Docker. It includes a comprehensive toolkit for speedy deployment, continuous monitoring, enterprise-level data governance, to save developers’ valuable time from toil.

![Key Features of FISCO BCOS 2.0](https://raw.githubusercontent.com/FISCO-BCOS/LargeFiles/master/images/plane_en.png)

For more information, please refer to new features in [version 2.0](https://fisco-bcos-documentation.readthedocs.io/zh_CN/latest/docs/what_is_new.html)

## Quick Start

Read [Quick Start](https://fisco-bcos-documentation.readthedocs.io/zh_CN/latest/docs/installation.html) to learn the installation and deployment procedures, and experience the rich features of FISCO BCOS.

## Technical documentation

- [**English**](https://fisco-bcos-documentation.readthedocs.io/en/latest/)
- [**中文**](https://fisco-bcos-documentation.readthedocs.io/zh_CN/latest/)

## Featured applications

**FISCO BCOS** has been adopted in over 10 applications in areas like government affairs, finances, charity, health care, education, transport, copyright, product tracing, supply chain, recruitment, agriculture, social communication, and entertainment.

- Finance: inter-institutional reconciliation, supply chain finance, tourism finance, etc.
- Judicial services: arbitration chain, digital IOUs, etc.
- Copyright: copyright registration and trading, etc.
- Social management: real-estate registration, etc.

Featured use cases are provided [here](http://www.fisco-bcos.org/assets/docs/FISCO%20BCOS%20-%20Featured%20Cases.pdf).

## Code contribution

- Your contributions are most welcome and appreciated. Please read the [contribution instructions](https://mp.weixin.qq.com/s/_w_auH8X4SQQWO3lhfNrbQ) and [coding code style guide](CODING_STYLE.md).
- If this project is useful to you, please star us on GitHub project page!

## Join Our Community

The FISCO BCOS community is one of the most active open-source blockchain communities in China. It provides long-term technical support for both institutional and individual developers and users of FISCO BCOS. Thousands of technical enthusiasts from numerous industry sectors have joined this community, studying and using FISCO BCOS platform. If you are also interested, you are most welcome to join us for more support and fun.

![](https://raw.githubusercontent.com/FISCO-BCOS/LargeFiles/master/images/QR_image_en.png)

## License

[![](https://img.shields.io/github/license/FISCO-BCOS/FISCO-BCOS.svg)](LICENSE)

All contributions are made under the [GNU General Public License v3](https://www.gnu.org/licenses/gpl-3.0.en.html). See [LICENSE](LICENSE).
