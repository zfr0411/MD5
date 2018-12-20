//
//  MD5.hpp
//  MD5
//
//  Created by 周芙蓉 on 2018/11/26.
//  Copyright © 2018 周芙蓉. All rights reserved.
//

#ifndef MD5_hpp
#define MD5_hpp

#include <stdio.h>
#include<iostream>
#include <string.h>
#include <cstring>
using std::string;
using namespace std;
/* MD5的参数 */
#define s11 7
#define s12 12
#define s13 17
#define s14 22
#define s21 5
#define s22 9
#define s23 14
#define s24 20
#define s31 4
#define s32 11
#define s33 16
#define s34 23
#define s41 6
#define s42 10
#define s43 15
#define s44 21

/*
 @Basic MD5 functions.
 
 @param there bit32.
 
 @return one bit32.
 */

#define F(x, y, z) (((x) & (y)) | ((~x) & (z)))
#define G(x, y, z) (((x) & (z)) | ((y) & (~z)))
#define H(x, y, z) ((x) ^ (y) ^ (z))
#define I(x, y, z) ((y) ^ ((x) | (~z)))

/*
 @Rotate Left.
 
 @param {num} the raw number.
 
 @param {n} rotate left n.
 
 @return the number after rotated left.
 */

#define ROTATELEFT(num, n) (((num) << (n)) | ((num) >> (32-(n))))

/*
 @Transformations for rounds 1, 2, 3, and 4.
 FF(a,b,c,d,x,s,ac）表示 a = b + ((a + F(b,c,d) + x + ac) << s)
 
 GG(a,b,c,d,x,s,ac）表示 a = b + ((a + G(b,c,d) + x + ac) << s)
 
 HH(a,b,c,d,x,s,ac）表示 a = b + ((a + H(b,c,d) + x + ac) << s)
 
 Ⅱ（a,b,c,d,x,s,ac）表示 a = b + ((a + I(b,c,d) + x + ac) << s)
 */

#define FF(a, b, c, d, x, s, ac) { \
(a) += F ((b), (c), (d)) + (x) + ac; \
(a) = ROTATELEFT ((a), (s)); \
(a) += (b); \
}
#define GG(a, b, c, d, x, s, ac) { \
(a) += G ((b), (c), (d)) + (x) + ac; \
(a) = ROTATELEFT ((a), (s)); \
(a) += (b); \
}
#define HH(a, b, c, d, x, s, ac) { \
(a) += H ((b), (c), (d)) + (x) + ac; \
(a) = ROTATELEFT ((a), (s)); \
(a) += (b); \
}
#define II(a, b, c, d, x, s, ac) { \
(a) += I ((b), (c), (d)) + (x) + ac; \
(a) = ROTATELEFT ((a), (s)); \
(a) += (b); \
}

/* Define of btye.*/
typedef unsigned char byte;
/* Define of byte. */
typedef unsigned int bit32;

//实现MD5类方法
class MD5 {
public:
    // 声明构造函数
    MD5(const string& message);
    //生成MD5摘要
    const byte* getDigest();
    //将摘要转成字符串
    string toStr();
private:
    //初始化MD5对象，处理另一个消息块，和更新上下文。MD5算法操作核心
    void init(const byte* input, size_t len);
    //MD5基本转换，块的基本转换
    void transform(const byte block[64]);
    //编码
    void encode(const bit32* input, byte* output, size_t length);
    //解码
    void decode(const byte* input, bit32* output, size_t length);
    //判断是否计算完毕
    bool finished;
    /* state (ABCD). */
    bit32 state[4];
   //小端数据
    bit32 count[2];
    //输入缓存
    byte buffer[64];
    //消息摘要
    byte digest[16];
    //填充计算
    static const byte PADDING[64];
    //16进制码
    static const char HEX_NUMBERS[16];
};
#endif /* MD5_hpp */
