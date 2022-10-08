#ifndef MACRO_LENGTH_H
#define MACRO_LENGTH_H
class Length {
public:
    explicit Length(int value);
    /*
    with explicit keyword, the compiler will not allow implicit conversion: Length l = 10;
     */
    //  getter and setter
    int getValue() const;
    /*
    const at the end of the function declaration means that the function will not modify the object
     */
    void setValue(int value);
    //  == compare operator
    bool operator==(const Length &other) const;

private:
    int value;
};
#endif // MACRO_LENGTH_H
