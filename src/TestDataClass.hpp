#pragma clang diagnostic push
#pragma ide diagnostic   ignored "cppcoreguidelines-avoid-magic-numbers"
#ifndef OPENCMW_CPP_IOCLASSSERIALISERBENCHMARK_H
#define OPENCMW_CPP_IOCLASSSERIALISERBENCHMARK_H
#include <numeric>
#include <random>
#include <opencmw/opencmw.hpp>
#include <opencmw/MultiArray.hpp>

using opencmw::MultiArray;
using std::array;
using std::string;
using std::unique_ptr;
using std::vector;

struct TestDataClass {
    // basic data type
    bool   bool1;
    bool   bool2;
    int8_t byte1;
    int8_t byte2;
    char   char1;
    char   char2;
    short  short1;
    short  short2;
    int    int1;
    int    int2;
    long   long1;
    long   long2;
    float  float1;
    float  float2;
    double double1;
    double double2;
    string string1;
    string string2;

    // 1-dim arrays
    vector<bool> boolArray;
    vector<int8_t>  byteArray;
    // vector<int8_t> charArray;
    vector<int16_t> shortArray;
    vector<int32_t> intArray;
    vector<int64_t> longArray;
    vector<float>   floatArray;
    vector<double>  doubleArray;
    vector<string>  stringArray;

    // generic n-dim arrays - N.B. striding-arrays: low-level format is the same except of 'nDimension' descriptor
    MultiArray<bool, 3>    boolNdimArray;
    MultiArray<uint8_t, 3> byteNdimArray;
    MultiArray<int16_t, 3> shortNdimArray;
    MultiArray<int32_t, 3> intNdimArray;
    MultiArray<int64_t, 3> longNdimArray;
    MultiArray<float, 3>   floatNdimArray;
    MultiArray<double, 3>  doubleNdimArray;

    // nested class
    unique_ptr<TestDataClass> nestedData;

    /**
     * @param nSizePrimitives size of primitive arrays (smaller 0: do not initialise fields/allocate arrays)
     * @param nSizeString size of String[] array (smaller 0: do not initialise fields/allocate arrays)
     * @param nestedClassRecursion how many nested sub-classes should be allocated
     */
    TestDataClass(const int nSizePrimitives = -1, const int nSizeString = -1, const int nestedClassRecursion = -1) {
        if (nestedClassRecursion > 0) {
            nestedData = std::make_unique<TestDataClass>(TestDataClass(nSizePrimitives, nSizeString, nestedClassRecursion - 1));
            nestedData->init(nSizePrimitives + 1, nSizeString + 1); //N.B. '+1' to have different sizes for nested classes
        }
        init(nSizePrimitives, nSizeString);
    }

    //auto operator<=>(const TestDataClass&) const = default;
    auto operator==(const TestDataClass &other) const {
        // N.B. yes, this is a stupid comparator since the <=> operator that is generated by default
        // tests for reference identity of smart pointers rather than it's values
        // ... since we have a mixed class, we need to implement it manually
        if (bool1 != other.bool1) return false;
        if (bool2 != other.bool2) return false;
        if (byte1 != other.byte1) return false;
        if (byte2 != other.byte2) return false;
        if (char1 != other.char1) return false;
        if (char2 != other.char2) return false;
        if (short1 != other.short1) return false;
        if (short2 != other.short2) return false;
        if (int1 != other.int1) return false;
        if (int2 != other.int2) return false;
        if (long1 != other.long1) return false;
        if (long2 != other.long2) return false;
        if (float1 != other.float1) return false;
        if (float2 != other.float2) return false;
        if (double1 != other.double1) return false;
        if (double2 != other.double2) return false;
        if (string1 != other.string1) return false;
        if (string2 != other.string2) return false;
        if (boolArray != other.boolArray) return false;
        if (byteArray != other.byteArray) return false;
        //if (charArray != other.charArray) return false;
        if (shortArray != other.shortArray) return false;
        if (intArray != other.intArray) return false;
        if (longArray != other.longArray) return false;
        if (floatArray != other.floatArray) return false;
        if (doubleArray != other.doubleArray) return false;
        if (stringArray != other.stringArray) return false;

        if (boolNdimArray != other.boolNdimArray) return false;
        if (byteNdimArray != other.byteNdimArray) return false;
        //if (charNdimArray != other.charNdimArray) return false;
        if (shortNdimArray != other.shortNdimArray) return false;
        if (intNdimArray != other.intNdimArray) return false;
        if (longNdimArray != other.longNdimArray) return false;
        if (floatNdimArray != other.floatNdimArray) return false;
        if (doubleNdimArray != other.doubleNdimArray) return false;

        if (!nestedData && !other.nestedData) return true;
        if ((nestedData && !other.nestedData) || (!nestedData && other.nestedData)) {
            return false;
        }
        if (*nestedData.get() != *other.nestedData.get()) return false;
        return true;
    }

    void clear() {
        bool1   = false;
        bool2   = false;
        byte1   = 0;
        byte2   = 0;
        char1   = 0;
        char2   = 0;
        short1  = 0;
        short2  = 0;
        int1    = 0;
        int2    = 0;
        long1   = 0;
        long2   = 0;
        float1  = 0;
        float2  = 0;
        double1 = 0;
        double2 = 0;

        string1 = "";
        string2 = "";

        // reset 1-dim arrays
        boolArray.clear();
        byteArray.clear();
        // charArray.clear();
        shortArray.clear();
        intArray.clear();
        longArray.clear();
        floatArray.clear();
        doubleArray.clear();
        stringArray.clear();

        // reset n-dim arrays
        boolNdimArray.clear();
        byteNdimArray.clear();
        // charNdimArray.clear();
        shortNdimArray.clear();
        intNdimArray.clear();
        longNdimArray.clear();
        floatNdimArray.clear();
        doubleNdimArray.clear();

        // nestedData = null;
    }

    void init(const int nSizePrimitives, const int nSizeString) {
        // Seed with a real random value, if available
        std::random_device r;
        // Choose a random mean between 1 and 6
        std::default_random_engine e1(r());
        if (nSizePrimitives >= 0) {
            bool1   = true;
            bool2   = false;
            byte1   = 10;
            byte2   = -100;
            char1   = 'a';
            char2   = 'Z';
            short1  = 20;
            short2  = -200;
            int1    = 30;
            int2    = -300;
            long1   = 40;
            long2   = -400;
            float1  = 50.5f;
            float2  = -500.5f;
            double1 = 60.6;
            double2 = -600.6;

            string1 = "Hello World!";
            string2 = "Γειά σου Κόσμε!";

            // allocate 1-dim arrays
            boolArray.resize(static_cast<std::size_t>(nSizePrimitives));
            std::generate(boolArray.begin(), boolArray.end(), [&]() { return e1() % 2 == 0; });
            byteArray.resize(static_cast<std::size_t>(nSizePrimitives));
            std::generate(byteArray.begin(), byteArray.end(), [&]() {return static_cast<uint8_t>(e1()); });
            // charArray.resize(static_cast<std::size_t>(nSizePrimitives));
            // std::generate(charArray.begin(), charArray.end(), [&](){return static_cast<uint_8t>(e1()); });
            shortArray.resize(static_cast<std::size_t>(nSizePrimitives));
            std::generate(shortArray.begin(), shortArray.end(), [&]() {return static_cast<short>(e1()); });
            intArray.resize(static_cast<std::size_t>(nSizePrimitives));
            std::generate(intArray.begin(), intArray.end(), [&]() {return static_cast<int>(e1()); });
            longArray.resize(static_cast<std::size_t>(nSizePrimitives));
            std::generate(longArray.begin(), longArray.end(), [&]() {return static_cast<long>(e1()); });
            floatArray.resize(static_cast<std::size_t>(nSizePrimitives));
            std::generate(floatArray.begin(), floatArray.end(), [&]() {return static_cast<float>(e1()); });
            doubleArray.resize(static_cast<std::size_t>(nSizePrimitives));
            std::generate(doubleArray.begin(), doubleArray.end(), [&]() {return static_cast<double>(e1()); });

            // allocate n-dim arrays -- N.B. for simplicity the dimension/low-level backing size is const
            boolNdimArray = MultiArray<bool, 3>({2,3,2});
            std::generate(boolNdimArray.elements().begin(), boolNdimArray.elements().end(), [&]() { return e1() % 2 == 0; });
            byteNdimArray = MultiArray<uint8_t , 3>({2,3,2});
            std::generate(byteNdimArray.elements().begin(), byteNdimArray.elements().end(), [&]() {return static_cast<uint8_t>(e1()); });
            // charNdimArray.resize(static_cast<std::size_t>(nMultiDim));
            // std::generate(charNdimArray.begin(), charNdimArray.end(), []() {return static_cast<uint8_t>(e1()); });
            shortNdimArray = MultiArray<short, 3>({2,3,2});
            std::generate(shortNdimArray.elements().begin(), shortNdimArray.elements().end(), [&]() {return static_cast<short>(e1()); });
            intNdimArray = MultiArray<int, 3>({2,3,2});
            std::generate(intNdimArray.elements().begin(), intNdimArray.elements().end(), [&]() {return static_cast<int>(e1()); });
            longNdimArray = MultiArray<long, 3>({2,3,2});
            std::generate(longNdimArray.elements().begin(), longNdimArray.elements().end(), [&]() {return static_cast<long>(e1()); });
            floatNdimArray = MultiArray<float, 3>({2,3,2});
            std::generate(floatNdimArray.elements().begin(), floatNdimArray.elements().end(), [&]() {return static_cast<float>(e1()); });
            doubleNdimArray = MultiArray<double, 3>({2,3,2});
            std::generate(doubleNdimArray.elements().begin(), doubleNdimArray.elements().end(), [&]() {return static_cast<double>(e1()); });
        }
        if (nSizeString >= 0) {
            for (int i = 0; i < nSizeString; i++) {
                stringArray.emplace_back(string1);
            }
        } else {
            stringArray.clear();
        }
    }
    static size_t get_data_size(const int nSizePrimitives = -1, const int nSizeString = -1, const int nestedClassRecursion = -1) {
        size_t dataSize = 0;
        if (nestedClassRecursion > 0) {
            dataSize += get_data_size(nSizePrimitives, nSizeString, nestedClassRecursion-1);
        }
        dataSize += 2 * sizeof(bool);
        dataSize += 2 * sizeof(int8_t);
        dataSize += 2 * sizeof(char);
        dataSize += 2 * sizeof(short);
        dataSize += 2 * sizeof(int);
        dataSize += 2 * sizeof(long);
        dataSize += 2 * sizeof(float);
        dataSize += 2 * sizeof(double);
        auto string1 = std::string("Hello World!");
        dataSize += string1.size();
        auto string2 = std::string("Γειά σου Κόσμε!");
        dataSize += string2.size();

        dataSize += static_cast<size_t>(nSizePrimitives) * sizeof(uint8_t); // bool arrays are special
        dataSize += static_cast<size_t>(nSizePrimitives) * sizeof(int8_t);
        dataSize += static_cast<size_t>(nSizePrimitives) * sizeof(short);
        dataSize += static_cast<size_t>(nSizePrimitives) * sizeof(int);
        dataSize += static_cast<size_t>(nSizePrimitives) * sizeof(long);
        dataSize += static_cast<size_t>(nSizePrimitives) * sizeof(float);
        dataSize += static_cast<size_t>(nSizePrimitives) * sizeof(double);

        if (nSizeString > 0) {
            throw std::invalid_argument("string contents not implemented");
        }

        // multi dim data left as default content
        size_t nDims = 2 * 3 * 2;
        dataSize += nDims * sizeof(uint8_t);
        dataSize += nDims * sizeof(int8_t);
        dataSize += nDims * sizeof(short);
        dataSize += nDims * sizeof(int);
        dataSize += nDims * sizeof(long);
        dataSize += nDims * sizeof(float);
        dataSize += nDims * sizeof(double);

        return dataSize;
    }
};
ENABLE_REFLECTION_FOR(TestDataClass, bool1, bool2, byte1, byte2, char1, char2, short1, short2, int1, int2, long1, long2, float1, float2, double1, double2, string1, string2, // basic variables
        boolArray, byteArray, shortArray, intArray, longArray, floatArray, doubleArray, stringArray,                                                                         // basic 1D-arrays
        boolNdimArray, byteNdimArray, shortNdimArray, intNdimArray, longNdimArray, floatNdimArray, doubleNdimArray,                                                          // basic ND-arrays
        nestedData                                                                                                                                                           // nested class
)

#endif //OPENCMW_CPP_IOCLASSSERIALISERBENCHMARK_H

#pragma clang diagnostic pop