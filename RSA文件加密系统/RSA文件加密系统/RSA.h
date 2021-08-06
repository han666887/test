#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <time.h>
#include <fstream>

struct Key {
	//公钥(public_key, share_key)
	long long share_key;
	long long public_key;
	//私钥(private_key, share_key)
	long long private_key;
};

class RSA {
public:
	RSA();
	Key GetKey() {
		return _key;
	}
	//给文件进行加密
	void Ecrept(const char* plain_file_in, const char* ecrept_file_out,
		long public_key, long share_key);
	void DEcrept(const char* plain_file_in, const char* ecrept_file_out,
		long private_key, long share_key);

	//对字符串进行加密
	std::vector<long> Ecrept(std::string& str_in, long public_key, long share_key);
	std::string DEcrept(std::vector<long>& ecrept_str, long private_key, long share_key);

	//打印加密之后的信息
	void PrintInfo(std::vector<long>& ecrept_str);
private:
	//产生素数
	long ProducePrime();
	//判断一个数是否是素数
	bool IsPrime(long prime);
	//产生所有的key值
	void ProduceKeys();
	//求share_kay
	long ProduceShareKey(long prime1, long prime2);
	//根据欧拉函数求乘积
	long ProduceOrla(long prime1, long prime2);
	//求public_key
	long ProducePublicKey(long orla);
	//判断两个数之间的最大公约是否为1
	long ProduceGcd(long public_key, long orla);
	//求private_key
	long ProducePrivateKey(long public_key, long orla);
	//加密单个信息
	long Ecrept(long msg, long key, long share_key);
private:
	Key _key;
};
