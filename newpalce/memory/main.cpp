// // // #include <iostream>
// // // #include <string>
// // // inline int getsize(const std::string &s)
// // // {
// // //     char temp = s.back();
// // //     if (temp == 'M')
// // //         return 0;
// // //     if (temp == 'L')
// // //         return 1;
// // //     if (temp == 'S')
// // //         return -1;
// // // }
// // // inline int countXinString(const std::string &s, char x)
// // // {
// // //     int count = 0;
// // //     for (int i = 0; i < s.size(); i++)
// // //     {
// // //         if (s[i] == x)
// // //             count++;
// // //     }
// // //     return count;
// // // }
// // // int main()
// // // {
// // //     int n;
// // //     std::cin >> n;
// // //     std::string s1, s2;
// // //     for (int i = 0; i < n; i++)
// // //     {
// // //         std::cin >> s1;
// // //         std::cin >> s2;
// // //         if (getsize(s1) == getsize(s2))
// // //         {
// // //             int c1 = countXinString(s1, 'X');
// // //             int c2 = countXinString(s2, 'X');
// // //             if (c1 == c2)
// // //             {
// // //                 std::cout << "=\n";
// // //             }
// // //             else if (c1 > c2)
// // //             {
// // //                 getsize(s1) == 1 ? std::cout << ">\n" : std::cout << "<\n";
// // //             }
// // //             else
// // //             {
// // //                 getsize(s1) == 1 ? std::cout << "<\n" : std::cout << ">\n";
// // //             }
// // //         }
// // //         else
// // //         {
// // //             getsize(s1) > getsize(s2) ? std::cout << ">\n" : std::cout << "<\n";
// // //         }
// // //     }
// // // }
// // #include <iostream>
// // #include <string>
// // bool endsWith(const std::string &str, const std::string &suffix)
// // {
// //     if (str.size() < suffix.size())
// //     {
// //         return false;
// //     }
// //     return std::equal(suffix.rbegin(), suffix.rend(), str.rbegin());
// // }
// // int main()
// // {
// //     int num;
// //     std::string s;
// //     std::cin >> num;
// //     for (int i = 0; i < num; i++)
// //     {
// //         std::cin >> s;
// //         if (endsWith(s, "po"))
// //         {
// //             std::cout << "FILIPINO" << std::endl;
// //         }
// //         else if (endsWith(s, "mnida"))
// //         {
// //             std::cout << "KOREAN" << std::endl;
// //         }
// //         else if (endsWith(s, "desu") || endsWith(s, "masu"))
// //         {
// //             std::cout << "JAPANESE" << std::endl;
// //         }
// //         else
// //         {
// //             std::cout << "Unknown language." << std::endl;
// //         }
// //     }
// // }
// #include <iostream>
// class Test
// {
// private:
//     static int count;
//     int data;

// public:
//     Test();
//     Test(const Test &t);
//     ~Test();
// };

// int Test::count = 0;

// Test::Test()
// {
//     count++;
//     this->data = 1;
//     std::cout << "Constructor called" << count << " is " << data << std::endl;
// }

// Test::Test(const Test &t)
// {
//     count++;
//     this->data = 2;
//     std::cout << "Constructor called" << count << " is " << data << std::endl;
// }

// Test::~Test()
// {
//     std::cout << "Destructor called" << std::endl;
// }

// Test f()
// {
//     Test t;
//     return t;
// }

// int main()
// {
//     Test t1;
//     Test t2 = std::move(t1);
//     Test t3 = f();
//     return 0;
// }

