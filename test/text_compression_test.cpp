#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark_all.hpp>
#include "text_compression.h"

using namespace std;

TEST_CASE("Huffman encode/decode (Figure 12.8)")
{
    string data = "a fast runner need never be afraid of the dark";
	TextCompression tc(data);
    auto encoding = tc.encode();
    string encodingStr;
	for (bool bit : encoding) {
		encodingStr += bit ? "1" : "0";
	}
    REQUIRE(encodingStr == "100001010100101100111100001010110111101110"
                           "110010001110110110011100111011010111111001"
                           "000111110110001001010010100111111011100011"
                           "001010001111001101110000111100010101110");
	REQUIRE(tc.decode(encoding) == data);
}
