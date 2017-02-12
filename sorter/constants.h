#ifndef __CONSTANTS_H__
#define __CONSTANTS_H__

//Vector file names
const static std::string ORD_VEC_MIN_MAX_NAME = "Ordered Vector (min. to max.)";
const static std::string ORD_VEC_MAX_MIN_NAME = "Ordered Vector (max. to min.)";
const static std::string RANDOM_VECTOR_NAME = "Random Vector";

//Vector file types
const static int ORDERED_VECTOR_MIN_MAX = 1;
const static int ORDERED_VECTOR_MAX_MIN = 2;
const static int RANDOM_VECTOR = 3;

//File names
const static std::string ORDERED_VECTOR_FILENAME = "ordered_vec.bin";
const static std::string RANDOM_VECTOR_FILENAME = "random_vec.bin";

//Graphic points
const static std::vector<int> vSizes = {10, 100, 500, 1000, 5000, 10000, 25000, 50000, 75000, 100000};

#endif // __CONSTANTS_H__
