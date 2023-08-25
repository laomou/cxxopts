
#include <string>

namespace cl {

bool ParseCommandLineOptions(int argc, const char *const *argv);

class Option {};

template <class DataType>
class opt_storage {
 public:
  DataType value_;

  opt_storage() : value_(DataType()) {}

  template <class T>
  void setValue(const T &v) {
    value_ = v;
  }
  DataType &getValue() { return value_; }
  DataType getValue() const { return value_; }
  operator DataType() const { return getValue(); }
  DataType operator->() const { return value_; }
};

template <class DataType>
class opt : public Option, public opt_storage<DataType> {
 public:
  opt(const opt &) = delete;
  opt &operator=(const opt &) = delete;

  constexpr opt(const char* v) {
  }

  template <class T>
  DataType &operator=(const T &val) {
    this->setValue(val);
    return this->getValue();
  }
};

}  // namespace cl