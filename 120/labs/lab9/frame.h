/*
	Charles Park
	Section 5
	3/22/23
	Lab 9
*/

class frame {
    private:
        int width;
        int height;

    public:
        frame() {
            width = 1;
            height = 1;
        }
        frame(int length) {
            if (length < 1) {
                length = 1;
            }
            width = length;
            height = length;
        }
        frame(int _width, int _height) {
            if (_width < 1) {
                _width = 1;
            }
            if (_height < 1) {
                _height = 1;
            }
            width = _width;
            height = _height;
        }

        void set(int length) {
            if (length < 1) {
                length = 1;
            }
            width = length;
            height = length;
        }
        void set(int _width, int _height) {
            if (_width < 1) {
                _width = 1;
            }
            if (_height < 1) {
                _height = 1;
            }
            width = _width;
            height = _height;
        }

        void draw() {
            for (int i = 0; i < height + 2; i++) {
                for (int j = 0; j < width + 2; j++) {
                    if (i == 0 || i == height + 1) {
                        cout << "* ";
                    } else {
                        if (j == 0 || j == width + 1) {
                            cout << "* ";
                        } else {
                            cout << "  ";
                        }
                    }
                }
                cout << "\n";
            }
        }
};
