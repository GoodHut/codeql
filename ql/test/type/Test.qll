import ql

class Strings extends string {
  Strings() { this = ["", "f", "o", "foo", "bar", "b", "a", "r", "ba", "ar"] }
}

class Floats extends float {
  Floats() { this = [0.0, 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0] }
}

string conc(Strings a, Strings b) { result = a + b }

float floats(Floats a, Floats b) { result = a + b }
