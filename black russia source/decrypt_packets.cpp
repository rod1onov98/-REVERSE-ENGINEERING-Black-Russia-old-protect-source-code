uint8_t* decryptpackets(unsigned char *buf, int length, int port) {
    if (buf[0] == 31) {
        uint8_t* numArray1 = new uint8_t[length - 5];
        int length1 = (length - 5) / 4;

        uint8_t* numArray2 = buf + 5;
        uint8_t* numArray3 = buf + 5 + length1;
        uint8_t* numArray4 = buf + 5 + length1 * 2;
        uint8_t* numArray5 = buf + 5 + length1 * 3;

        if (buf[1] == 0) {
            for (int i = 0; i < length1; ++i)
                numArray1[i] = numArray2[i];
        }
        if (buf[1] == 1) {
            for (int i = 0; i < length1; ++i)
                numArray1[i] = numArray2[i];
        }
        if (buf[1] == 2) {
            for (int i = 0; i < length1; ++i)
                numArray1[i] = numArray2[i];
        }
        if (buf[1] == 3) {
            for (int i = 0; i < length1; ++i)
                numArray1[i] = numArray2[i];
        }
        if (buf[2] == 0) {
            for (int i = 0; i < length1; ++i)
                numArray1[i] = numArray3[i];
        }
        if (buf[2] == 1) {
            for (int i = 0; i < length1; ++i)
                numArray1[i] = numArray3[i];
        }
        if (buf[2] == 2) {
            for (int i = 0; i < length1; ++i)
                numArray1[i] = numArray3[i];
        }
        if (buf[2] == 3) {
            for (int i = 0; i < length1; ++i)
                numArray1[i] = numArray3[i];
        }
        if (buf[3] == 0) {
            for (int i = 0; i < length1; ++i)
                numArray1[i] = numArray4[i];
        }
        if (buf[3] == 1) {
            for (int i = 0; i < length1; ++i)
                numArray1[i] = numArray4[i];
        }
        if (buf[3] == 2) {
            for (int i = 0; i < length1; ++i)
                numArray1[i] = numArray4[i];
        }
        if (buf[3] == 3) {
            for (int i = 0; i < length1; ++i)
                numArray1[i] = numArray4[i];
        }
        if (buf[4] == 0) {
            for (int i = 0; i < length1; ++i)
                numArray1[i] = numArray5[i];
        }
        if (buf[4] == 1) {
            for (int i = 0; i < length1; ++i)
                numArray1[i] = numArray5[i];
        }
        if (buf[4] == 2) {
            for (int i = 0; i < length1; ++i)
                numArray1[i] = numArray5[i];
        }
        if (buf[4] == 3) {
            for (int i = 0; i < length1; ++i)
                numArray1[i] = numArray5[i];
        }

        int length2 = (length - 5) % 4;
        if (length2 > 0) {
            for (int i = 0; i < length2; ++i)
                numArray1[length1 * 4 + i] = buf[length1 * 4 + 5 + i];
        }

        return unKyretardizeDatagram(numArray1, length - 5, port, 0);
    } else {
        printf("[WARNING] wrong first byte " + ByteArrayToHexString(buf, length));
        return nullptr;
    }
}