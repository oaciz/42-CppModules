#ifndef DATA_HPP
#define DATA_HPP

class Data {
public:
    Data();
    Data(int deger);
    Data(const Data& other);
    ~Data();
    Data& operator=(const Data& other);

    int getValue() const;

private:
    int dataValue;
};

#endif // DATA_HPP
