void cleanup(uint8_t** numArray1, int size) {
    for (int i = 0; i < size; ++i) {
        delete[] numArray1[i];
    }
    delete[] numArray1;
}


void numArray(uint8_t* array, int length) {
    for (int i = 0; i < length; ++i) {
        array[i] = sampDecrTable[array[i]];
    }
}

void Log(const std::string& message) {
    std::cout << message << std::endl;
}

std::string intToString(int number) {
    return std::to_string(number);
}

std::string ByteArrayToHexString(const uint8_t* byteArray, int length) {
    std::string result;
    for (int i = 0; i < length; ++i) {
        result += "0x" + std::to_string(byteArray[i]) + " ";
    }
    return result;
}

uint8_t* cryptPackets(unsigned char *data, int length, int port) {
    if (data == nullptr)
        return nullptr;

    int totalLength = length + 6;
    uint8_t* destinationArray = new uint8_t[totalLength];

    destinationArray[0] = 31;
    destinationArray[1] = 0;
    destinationArray[2] = 1;
    destinationArray[3] = 2;
    destinationArray[4] = 3;

    kyretardizeDatagram(data, length, port, 0);

    int length1 = length / 4;

    uint8_t** numArray1 = new uint8_t*[4];
    for (int i = 0; i < 4; ++i) {
        numArray1[i] = new uint8_t[length1];
        for (int j = 0; j < length1; ++j)
            numArray1[i][j] = data[i * length1 + j];
    }

    for (int i = 0; i < 4; ++i)
        numArray(numArray1[i], length1);

    for (int index1 = 0; index1 < 4; ++index1) {
        for (int index2 = 0; index2 < length1; ++index2)
            destinationArray[index1 * length1 + index2 + 5] = numArray1[index1][index2];
    }

    int length3 = length % 4;
    if (length3 > 0) {
        for (int index = 0; index < length3; ++index)
            destinationArray[length1 * 4 + index + 5] = data[length1 * 4 + index];
    }

    for (int index = 0; index < totalLength; ++index)
        destinationArray[index] ^= 4;

    cleanup(numArray1, 4);

    return destinationArray;
}
