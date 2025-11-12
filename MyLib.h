#pragma once
#include <iostream>
#include <string>
#include <vector> // يفضل استخدام vector بدلاً من المصفوفات الثابتة
#include <ctime>
#include <cstdlib>
#include <limits>
#include <numeric>
#include <fstream>
#include <iomanip>
using namespace std;
// تعريف Enums لتسهيل فهم الخيارات
enum IsPrime {
    Prime,
    NotPrime
};

enum enCharactersType {
    None = 0,        // لا شيء
    SmallLetter = 1,   // الحروف الصغيرة
    CapitalLetter = 2,   // الحروف الكبيرة
    Digit = 3,   // الأرقام
    Space = 4,   // المسافات
    Punctuation = 5,   // علامات الترقيم
    All = 6
};
namespace clsDate
{







    // ---[ MathUtils: دوال العمليات الحسابية والمنطقية على الأعداد ]---

    // دالة لعكس رقم
    int ReverseNumber(int number) {
        int reminder = 0, reversedNumber = 0;
        while (number > 0) {
            reminder = number % 10;
            number = number / 10;
            reversedNumber = reversedNumber * 10 + reminder;
        }
        return reversedNumber;
    }

    // دالة للتحقق مما إذا كان الرقم هو Palindrome
    bool CheckIfPalindrome(int number) {
        return ReverseNumber(number) == number;
    }

    // دالة للتحقق مما إذا كان الرقم هو Perfect Number (العدد المثالي)
    // تم تعديل المنطق ليعمل بشكل صحيح
    bool CheckIfIsPerfectNumber(int number) {
        if (number <= 1) {
            return false;
        }

        int sum = 0;
        for (int i = 1; i < number; i++) {
            if (number % i == 0) {
                sum += i;
            }
        }
        return sum == number;
    }

    // دالة للتحقق مما إذا كان الرقم هو Prime (عدد أولي)
    IsPrime IsPrimeNumber(int number) {
        if (number <= 1) {
            return IsPrime::NotPrime;
        }
        for (int i = 2; i * i <= number; i++) {
            if (number % i == 0) {
                return IsPrime::NotPrime;
            }
        }
        return IsPrime::Prime;
    }

    // دالة لحساب تكرار رقم معين داخل عدد آخر
    int FrequencyInNumber(int number, int DigitTarget) {
        int reminder = 0;
        int frequency = 0;
        do {
            reminder = number % 10;
            number /= 10;
            if (reminder == DigitTarget) {
                frequency++;
            }
        } while (number != 0);

        return frequency;
    }

    // دالة لتوليد رقم عشوائي ضمن نطاق معين
    int GenRandomNumber(int from, int to) {
        return rand() % (to - from + 1) + from;
    }

    // ---[ ArrayUtils: دوال العمليات على المصفوفات ]---

    // دالة لإضافة عنصر إلى مصفوفة (مع تعديل حجم المصفوفة)
    void AddArrayElements(int number, int arr[], int& arrLength) {
        arrLength++;
        arr[arrLength - 1] = number;
    }

    // دالة لحساب مجموع الأرقام في مصفوفة
    int SumNumbersInArray(int arr[], int arrLength) {
        int Sum = 0;
        for (int i = 0; i < arrLength; i++) {
            Sum += arr[i];
        }
        return Sum;
    }

    // دالة لحساب متوسط الأرقام في مصفوفة
    float AverageOfNumbersInArray(int arrElements[], int arrLength) {
        if (arrLength == 0) return 0;
        return (float)SumNumbersInArray(arrElements, arrLength) / arrLength;
    }

    // دالة لإيجاد أصغر رقم في مصفوفة
    int MinNumberInArray(int arrElements[], int arrLength) {
        if (arrLength == 0) return 0; // التعامل مع المصفوفة الفارغة
        int minNumber = arrElements[0];
        for (int i = 1; i < arrLength; i++) {
            if (arrElements[i] < minNumber) {
                minNumber = arrElements[i];
            }
        }
        return minNumber;
    }

    // دالة لإيجاد أكبر رقم في مصفوفة
    int MaxNumberInArray(int arr[], int arrLength) {
        if (arrLength == 0) return 0; // التعامل مع المصفوفة الفارغة
        int maxNumber = arr[0];
        for (int i = 1; i < arrLength; i++) {
            if (arr[i] > maxNumber) {
                maxNumber = arr[i];
            }
        }
        return maxNumber;
    }

    // دالة للبحث عن رقم في مصفوفة وإرجاع موقعه
    int FindNumberPositionInArray(int arr[], int arrLength, int Target) {
        for (int i = 0; i < arrLength; i++) {
            if (Target == arr[i]) {
                return i;
            }
        }
        return -1;
    }
    int FindTextPositionInArray(string arr[], int arrLength, string Target) {
        for (int i = 0; i < arrLength; i++) {
            if (Target == arr[i]) {
                return i;
            }
        }
        return -1;
    }

    // دالة للتحقق مما إذا كان رقم موجوداً في مصفوفة
    bool IsNumberInArray(int arr[], int arrLength, int NumberToSearchFor) {
        return FindNumberPositionInArray(arr, arrLength, NumberToSearchFor) != -1;
    }

    // دالة لعد الأرقام الزوجية في مصفوفة
    int CountEvenNumbersInArray(int arr[], int arrLength) {
        int counter = 0;
        for (int i = 0; i < arrLength; i++) {
            if (arr[i] % 2 == 0) {
                counter++;
            }
        }
        return counter;
    }

    // دالة لعد الأرقام الفردية في مصفوفة
    int CountOddNumbersInArray(int arr[], int arrLength) {
        int counter = 0;
        for (int i = 0; i < arrLength; i++) {
            if (arr[i] % 2 != 0) {
                counter++;
            }
        }
        return counter;
    }

    // دالة لعد الأرقام الموجبة في مصفوفة
    int CountPositiveNumbersInArray(int arr[], int arrLength) {
        int counter = 0;
        for (int i = 0; i < arrLength; i++) {
            if (arr[i] > 0) {
                counter++;
            }
        }
        return counter;
    }

    // دالة لحساب عدد مرات تكرار رقم في مصفوفة
    int TimesRepeatedInArray(int arrElements[], int arrLength, int Digit) {
        int counter = 0;
        for (int i = 0; i < arrLength; i++) {
            if (Digit == arrElements[i]) {
                counter++;
            }
        }
        return counter;
    }

    // دالة لنسخ العناصر الفريدة من مصفوفة إلى أخرى
    void CopyDistinctArray(int arr[], int arrLength, int arr2[], int& arrLength2) {
        for (int i = 0; i < arrLength; i++) {
            if (!IsNumberInArray(arr2, arrLength2, arr[i])) {
                AddArrayElements(arr[i], arr2, arrLength2);
            }
        }
    }

    // دالة للتحقق مما إذا كانت المصفوفة هي Palindrome
    bool IsPalindromArray(int arrElements[], int arrLength) {
        for (int i = 0; i < arrLength / 2; i++) {
            if (arrElements[i] != arrElements[arrLength - 1 - i]) {
                return false;
            }
        }

        return true;
    }

    // دالة لخلط عناصر المصفوفة عشوائياً
    void ShuffleArrayElements(int arrElements[], int arrLength) {
        for (short i = 0; i < arrLength; i++) {
            swap(arrElements[GenRandomNumber(1, arrLength) - 1], arrElements[GenRandomNumber(1, arrLength) - 1]);
        }
    }

    // ---[ StringUtils: دوال توليد النصوص ]---

    // دالة لتوليد حرف عشوائي بناءً على الاختيار
    char GenerateCharacters(enCharactersType userChoice) {
        switch (userChoice) {
        case Punctuation:
            return char(GenRandomNumber(33, 47));
        case SmallLetter:
            return char(GenRandomNumber(97, 122));
        case CapitalLetter:
            return char(GenRandomNumber(65, 90));
        case Digit:
            return char(GenRandomNumber(48, 57));
        default:
            return ' '; // إرجاع قيمة افتراضية
        }
    }

    // دالة لتوليد كلمة عشوائية
    // تم تصحيح استخدام طول الكلمة
    string GenerateWord(enCharactersType enChar, int wordLength) {
        string word = "";
        for (int i = 0; i < wordLength; i++) {
            word += GenerateCharacters(enChar);
        }
        return word;
    }

    // دالة لتوليد مفتاح عشوائي
    string GenerateKey() {
        string key;
        key = GenerateWord(CapitalLetter, 4) + "-";
        key += GenerateWord(CapitalLetter, 4) + "-";
        key += GenerateWord(CapitalLetter, 4) + "-";
        key += GenerateWord(CapitalLetter, 4);
        return key;
    }

    // ---[ IOUtils: دوال الإدخال والإخراج ]---

    // دالة لطباعة عناصر مصفوفة
    void PrintArrays(int arr[], int arrLength) {
        for (int i = 0; i < arrLength; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    // دالة لقراءة حجم المصفوفة وتعبئتها بأرقام عشوائية
    void FillArrayWithRandomNumbers(int arr[], int& arrLength,int From,int To) {
        cout << "enter array length: ";
        cin >> arrLength;
        for (int i = 0; i < arrLength; i++) {
            arr[i] = GenRandomNumber(From, To);
        }
    }
    void FillArrayWithRandomWord(string arr[], int& arrLength, enCharactersType CharacterType, short WordLength) {
        cout << "enter array length: ";
        cin >> arrLength;
        for (int i = 0; i < arrLength; i++) {
            arr[i] = GenerateWord(CharacterType, WordLength);
        }
    }

    // دالة لقراءة رقم موجب من المستخدم
    int ReadPositiveNumber(string message, string ErrorMessage) {
        int number = 1;
        do {

            cout << message;
            cin >> number;
            while (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << ErrorMessage;
                cin >> number;
            }
        } while (number < 0);


        return number;
    }
    int ReadPositiveNumberInRange(string message, string ErrorMessage,int From,int To) {
        int number = 1;
        do {

            cout << message;
            cin >> number;
            while (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << ErrorMessage;
                cin >> number;
            }
        } while (number < From || number > To);


        return number;
    }

    // دالة لقراءة رقم صحيح والتحقق من صحة الإدخال
    int ReadValidNumber(string message, string ErrorMessage) {
        int number = 0;
        cout << message;
        cin >> number;
        while (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << ErrorMessage;
            cin >> number;
        }
        return number;
    }
    // Removes the first occurrence of `number` from `arr` and updates `arrLength`.

    void RemoveElement(int arr[], int& arrLength, int Target)
    {
        int StartPoint = FindNumberPositionInArray(arr, arrLength, Target);
        if (StartPoint != -1)
        {
            for (int i = StartPoint; i < arrLength - 1; i++)
            {

                arr[i] = arr[i + 1];

            }
            arrLength--;

        }
    }


    // Sort Array from the smallest number to the bigest number

    void SortArray(int arr[], int arrLength)
    {

        for (int i = 0; i < arrLength; i++)
        {
            int minIndex = i;
            for (int j = i; j < arrLength; j++)
            {
                if (arr[j] < arr[minIndex])
                {
                    minIndex = j;
                }
            }
            swap(arr[i], arr[minIndex]);
        }
    }

    // Remove Duplicate Elements in array
    void RemoveDuplicateElements(int arr[], int& arrLength)
    {
        SortArray(arr, arrLength);
        short UniqIndex = 0;
        for (int i = 0; i < arrLength; i++)
        {
            if (arr[i] != arr[UniqIndex])
            {
                UniqIndex++;
                arr[UniqIndex] = arr[i];
            }
        }
        arrLength = UniqIndex + 1;
    }

    void LoadFileDataToVector(const string& FilePath, vector <string> &vlines)
    {
        vlines.clear();
        fstream Myfile(FilePath, ios::in);
        string Line;

        if (Myfile.is_open())
        {
            while (getline(Myfile, Line))
            {
                vlines.push_back(Line);
            }
            Myfile.close();
        }
        else
        {
            cout << "Error: Could not open file \"" << FilePath << "\" for reading.\n";
            return;
        }
    }

    // append vector data to file in specifice path
    void AppendLinesInFile(const string& FilePath, vector <string>& vlines)
    {
        fstream Myfile(FilePath, ios::out | ios::app);//append mod
        if (Myfile.is_open())
        {
            for (string& i : vlines)
            {
                Myfile << i << "\n";
            }
            Myfile.close();
        }
        else
        {
            cout << "Error: Could not open file \"" << FilePath << "\" for appending.\n";
            return;
        }
    }

    // save vector data to file in specifice path
    void SaveVectorToFile(const string& FilePath, vector <string>& vlines)
    {
        fstream Myfile(FilePath, ios::out);//append mod
        if (Myfile.is_open())
        {
            for (string& i : vlines)
            {
                if (!i.empty())
                    Myfile << i << endl;
            }
            Myfile.close();

        }
        else
        {
            cout << "Error: Could not open file \"" << FilePath << "\" for writing.\n";
        }

    }
    // show file content on the screen
    void PrintfileContent(const string& FilePath)
    {
        fstream Myfile(FilePath, ios::in);
        if (Myfile.is_open())
        {
            string line;
            while (getline(Myfile, line))
            {
                cout << line << endl;
            }
            Myfile.close();
        }
        else
        {
            cout << "Error: Could not open file \"" << FilePath << "\" for reading.\n";
            return;
        }
    }

    // Searches for a specific record in the file and clears its content.

    void DeleteRecordFromFile(const string& FilePath, string Record)
    {
        vector <string> vlines;
        LoadFileDataToVector(FilePath, vlines);
        for (string& i : vlines)
        {
            if (i == Record)
                i.clear();
        }
        SaveVectorToFile(FilePath, vlines);
    }


    void UpdateRecordInFile(const string& FilePath, string Record, string UpdatedRecord)
    {
        vector <string> vlines;
        LoadFileDataToVector(FilePath, vlines);
        for (string& i : vlines)
        {
            if (i == Record)
            {
                i = UpdatedRecord;
                break;
            }
        }
        SaveVectorToFile(FilePath, vlines);
    }


    void UpdateMultiRecordInFile(short NumberOfRecords, const string& FilePath)
    {

        string Record;
        string UpdatedRecord;

        for (int i = 1; i <= NumberOfRecords; i++)
        {
            cout << "enter record n[" << i << "]: ";
            getline(cin, Record);


            cout << "enter updated record n[" << i << "]: ";
            getline(cin, UpdatedRecord);


            UpdateRecordInFile(FilePath, Record, UpdatedRecord);
        }
    }

    void FillMatrixWithRandomNumbers(int arr[3][3], int Rows, int Cols, short From, short To)
    {
        for (int i = 0; i < Rows; i++)
        {

            for (int j = 0; j < Cols; j++)
            {
                arr[i][j] = GenRandomNumber(From, To);
            }
        }

    }


    void PrintMatrix(int arr[3][3], int Rows, int Cols, short PrintFormat)
    {
        for (int i = 0; i < Rows; i++)
        {

            for (int j = 0; j < Cols; j++)
            {
                if (PrintFormat == 0)
                    cout << left << setw(4) << arr[i][j] << "  ";
                else
                    printf("%0*d\t", 2, arr[i][j]);
            }
            cout << endl;
        }
    }

    int SumOfRowInMatrix(int arr[3][3], int Row, int Cols)
    {
        int sum = 0;

        for (int i = 0; i < Cols; i++)
        {
            sum += arr[Row][i];
        }
        return sum;
    }
    void FillRowSumInArray(int arr[], int Matrix[3][3], int Rows, int Cols)
    {

        for (int i = 0; i < Cols; i++)
        {
            arr[i] = SumOfRowInMatrix(Matrix, Rows, i);
        }

    }
    int ColsSum(int Matrix[3][3], int Row, int Cols)
    {
        int sum = 0;
        for (int i = 0; i < Row; i++)
        {
            sum += Matrix[i][Cols];

        }
        return sum;
    }
    void FillColSumInArray(int arr[], int Matrix[3][3], int Rows, int Cols)
    {

        for (int i = 0; i < Cols; i++)
        {
            arr[i] = ColsSum(Matrix, Rows, i);
        }

    }

    void MultiplyTwoMatirces(int Matrix1[3][3], int Matrix2[3][3], int Matrix3[3][3], int Rows, int Cols)
    {
        for (int i = 0; i < Rows; i++)
        {
            for (int j = 0; j < Cols; j++)
            {
                Matrix3[i][j] = (Matrix1[i][j] * Matrix2[i][j]);
            }
        }
    }
    int MatrixSum(int Matrix[3][3], int Rows, int Cols)
    {
        int sum = 0;
        for (int i = 0; i < Rows; i++)
        {
            for (int j = 0; j < Cols; j++)
            {
                sum += Matrix[i][j];
            }
        }
        return sum;
    }

    bool IsMatricesSumEqual(int Matrix1[3][3], int Matrix2[3][3], int Rows, int Cols)
    {
        return MatrixSum(Matrix1, Rows, Cols) == MatrixSum(Matrix2, Rows, Cols);
    }


    void PrintMatricesSumEqualResult(int Matrix1[3][3], int Matrix2[3][3], int Rows, int Cols)
    {
        bool IsEqual = IsMatricesSumEqual(Matrix1, Matrix2, Rows, Cols);
        (IsEqual) ? cout << "\n\nYes: matrices are equal! \n" : cout << "\n\nNo: matrices aren't equal! \n";
    }

    bool IsMatricesTypicalEqual(int Matrix1[3][3], int Matrix2[3][3], int Rows, int Cols)
    {
        for (int i = 0; i < Rows; i++)
        {
            for (int j = 0; j < Cols; j++)
            {
                if (Matrix1[i][j] != Matrix2[i][j])
                    return false;
            }
        }
        return true;
    }

    bool IsIndentityMatrix(int Matrix[3][3], int Rows, int Cols)
    {

        if (Rows != Cols)
            return false;


        for (int i = 0; i < Rows; i++)
        {
            for (int j = 0; j < Cols; j++)
            {
                if (i == j && Matrix[i][j] != 1 || i != j && Matrix[i][j] != 0)
                    return false;
            }
        }
        return true;
    }


    bool IsScalarMatrix(int Matrix[3][3], int Rows, int Cols)
    {
        if (Rows != Cols)
            return false;
        if (IsIndentityMatrix(Matrix, Rows, Cols))
            return true;
        short SpecialValue = Matrix[0][0];

        for (int i = 0; i < Rows; i++)
        {
            for (int j = 0; j < Cols; j++)
            {
                if (i == j && Matrix[i][j] != SpecialValue || i != j && Matrix[i][j] != 0)
                    return false;
            }
        }
        return true;
    }

    short CountNumberInMatrix(int Matrix[3][3], int Rows, int Cols, short Target)
    {
        short counter = 0;
        for (int i = 0; i < Rows; i++)
        {
            for (int j = 0; j < Cols; j++)
            {
                if (Matrix[i][j] == Target)
                    counter++;
            }
        }
        return counter;
    }


    bool IsSparseMatrix(int Matrix[3][3], int Rows, int Cols)
    {
        return CountNumberInMatrix(Matrix, Rows, Cols, 0) > Rows * Cols / 2;
    }

    bool IsNumberExistsInMatrix(int Matrix[3][3], int Rows, int Cols, int Target)
    {
        for (int i = 0; i < Rows; i++)
        {
            for (int j = 0; j < Cols; j++)
            {
                if (Matrix[i][j] == Target)
                    return true;
            }
        }
        return false;
    }


    void PrintIntersectedNumbersInMatrices(int Matrix1[3][3], int Matrix2[3][3], int Rows, int Cols)
    {

        for (int i = 0; i < Rows; i++)
        {
            for (int j = 0; j < Cols; j++)
            {
                if (IsNumberExistsInMatrix(Matrix2, Rows, Cols, Matrix1[i][j]))
                    cout << left << setw(3) << Matrix1[i][j] << "   ";
            }
        }

    }

    short FindMinNumberInMatrix(int Matrix[3][3], int Rows, int Cols)
    {
        short MinNumber = Matrix[0][0];
        for (int i = 0; i < Rows; i++)
        {
            for (int j = 0; j < Cols; j++)
            {
                if (MinNumber > Matrix[i][j])
                {
                    MinNumber = Matrix[i][j];
                }
            }

        }
        return MinNumber;

    }

    short FindMaxNumberInMatrix(int Matrix[3][3], int Rows, int Cols)
    {
        short MaxNumber = Matrix[0][0];
        for (int i = 0; i < Rows; i++)
        {
            for (int j = 0; j < Cols; j++)
            {
                if (MaxNumber < Matrix[i][j])
                {
                    MaxNumber = Matrix[i][j];
                }
            }

        }
        return MaxNumber;

    }

    bool IsPalindromMatrix(int Matrix[3][3], int Rows, int Cols)
    {
        for (int i = 0; i < Rows; i++)
        {

            for (int j = 0; j < Cols / 2; j++)
            {
                if (Matrix[i][j] != Matrix[i][Cols - j - 1])
                {
                    return false;
                }
            }


        }
        return true;
    }

    string UpperFirstLetterOfEachWord(string S1)
    {
        bool isFirstLetter = true;
        for (short i = 0; i < (short)S1.size(); i++)
        {
            if (S1.at(i) != ' ' && isFirstLetter)
            {
                S1.at(i) = tolower(S1.at(i));
            }
            isFirstLetter = (S1.at(i) == ' ') ? true : false;
        }
        return S1;
    }

    string ReadString(string Message)
    {
        string S1;
        cout << Message;
        getline(cin >> ws, S1);
        return S1;
    }

    string UpperAllLetterOfString(string S1)
    {
        for (short i = 0; i < (short)S1.size(); i++)
        {
            S1.at(i) = toupper(S1.at(i));
        }
        return S1;
    }

    string LowerAllLetterOfString(string S1)
    {
        for (short i = 0; i < (short)S1.size(); i++)
        {
            S1.at(i) = tolower(S1.at(i));
        }
        return S1;
    }

    char ReadLetter(string Message) {
        char letter;
        cout << Message;
        cin >> letter;
        return letter;
    }

    char InvertCharacter(char Letter)
    {
        if (isupper(Letter))
            return tolower(Letter);
        else
            return toupper(Letter);

    }

    string InvertString(string text)
    {

        for (short i = 0; i < static_cast<short>(text.size()); i++)
        {
            text.at(i) = clsDate::InvertCharacter(text.at(i));
        }
        return text;
    }

    short CountSmallLetterInString(string& text)
    {
        short counter = 0;
        for (int i = 0; i < text.size(); i++)
        {
            if (islower(text.at(i)))
                counter++;
        }
        return counter;
    }
    short CountCapitalLetterInString(string& text)
    {
        short counter = 0;

        for (int i = 0; i < text.size(); i++)
        {
            if (isupper(text.at(i)))
                counter++;
        }

        return counter;
    }

    short CountLetterInString(string text, enCharactersType LetterToCount)
    {
        short counter = 0;



        for (int i = 0; i < text.size(); i++)
        {

            if (isupper(text.at(i)) && LetterToCount == CapitalLetter)
                counter++;

            else if (islower(text.at(i)) && LetterToCount == SmallLetter)
                counter++;
        }
        return counter;
    }

    short CountSpecificeLetterInString(const string& text, char Target)
    {
        short counter = 0;

        for (int i = 0; i < text.size(); i++)
        {
            if (toupper(text.at(i)) == toupper(Target))
                counter++;
        }

        return counter;
    }

    short CountSpecificeLetterInString(const string& text, char Target, bool Match = true)
    {
        short counter = 0;

        for (int i = 0; i < text.size(); i++)
        {
            if (Match)
            {
                if (text.at(i) == Target)
                    counter++;
            }
            else
            {
                if (toupper(text.at(i)) == toupper(Target))
                    counter++;
            }

        }
        return counter;
    }


    bool IsVowel(char Letter)
    {
        Letter = tolower(Letter);
        return (Letter == 'a' || Letter == 'i' || Letter == 'e' || Letter == 'u' || Letter == 'o');
    }


    int CountVowelInString(string& text)
    {
        int counter = 0;
        for (int i = 0; i < text.size(); i++)
        {
            if (IsVowel(text.at(i)))
                counter++;
        }
        return counter;
    }


    short CountEachWordInString(string& text)
    {
        string Dilimiter = " ";
        string word = "";
        short position = 0;
        short counter = 0;
        while ((position = text.find(Dilimiter)) != string::npos)
        {
            word = text.substr(0, position);
            if (!word.empty())
            {
                counter++;
                word.clear();
            }
            text.erase(0, position + Dilimiter.length());
        }
        if (!text.empty())
            counter++;


        return counter;
    }


    vector <string> SplitText(string& text, string Dilimiter = " #//# ")
    {
        vector <string> vString;

        string word = "";
        short position = 0;

        while ((position = text.find(Dilimiter)) != string::npos)
        {
            word = text.substr(0, position);
            if (!word.empty())
            {
                vString.push_back(word);

                word.clear();
            }
            text.erase(0, position + Dilimiter.length());
        }
        if (!text.empty())
        {
            vString.push_back(text);

        }
        return vString;
    }



    string TrimLeft(string text)
    {
        string space = " ";
        short position = 0;
        while ((position = text.find(space)) == 0)
        {

            text.erase(0, position + space.length());
        }
        return text.substr(0, text.size());
        
    }

    short IndexFirstCharacterFromRight(string text)
    {
        if (text.empty())
        {
            for (short i = text.size() - 1; i >= 0; i--)
            {
                if (!isspace(text.at(i)))
                {
                    return i;
                }
            }
        }
        return 0;
    }

    string TrimRight(string text)
    {
        string result = "";
        short LasttLetterPostion = IndexFirstCharacterFromRight(text);
        result = text.substr(0, LasttLetterPostion + 1);
        return result;
    }

    string TrimText(string text)
    {
        return TrimRight(TrimLeft(text));
    }


    string JoinString(vector <string>& vText, const string& Dilimiter)
    {
        string text = "";

        for (string& i : vText)
        {
            text += i + Dilimiter;

        }
        return text.substr(0, text.size() - Dilimiter.length());
    }

    string JoinString(string arrNames[], short arrLength, const string& Dilimiter)
    {
        string text = "";

        for (short i = 0; i < arrLength; i++)
        {
            text += arrNames[i] + Dilimiter;
        }


        return text.substr(0, text.size() - Dilimiter.length());
    }


    string ReverceString(string& text)
    {
        string result = "";
        string Dilimiter = " ";
        vector <string> vSplitString = clsDate::SplitText(Dilimiter, text);
        for (int i = vSplitString.size() - 1; i >= 0; i--)
        {
            result += vSplitString.at(i) + Dilimiter;
        }

        return result.substr(0, result.size() - Dilimiter.length());
    }


    // USING SPLIT STRING METHOD
    string ReplceWordInStringMethod1(string& text, string& Target, string& NewWord)
    {
        string Dilimiter = " ";
        vector <string> vSplitString = clsDate::SplitText(Dilimiter, text);
        for (int i = 0; i < vSplitString.size(); i++)
        {
            if (Target == vSplitString.at(i))
            {
                vSplitString.at(i).assign(NewWord);

            }
        }

        return clsDate::JoinString(vSplitString, Dilimiter);
    }

    // USING REPLACE BUILT IN FUNCTION
    string ReplceWordInStringMethod2(string& text, string Target, string NewWord)
    {

        short pos = text.find(Target);
        string result = "";
        while (pos != string::npos)
        {

            result = text.replace(pos, Target.length(), NewWord);
            pos = text.find(Target);
        }
        return result;
    }

    string RemovePunctInString(string& text)
    {
        string S2 = "";
        for (int i = 0; i < text.size(); i++)
        {
            if (!ispunct(text.at(i)))
            {
                S2 += text.at(i);
            }
        }

        return S2;
    }

    bool isLeapYear(short& Year)
    {
        return (Year % 400 == 0 || (Year % 4 == 0 && Year % 100 != 0));
    }
    int NumberOfDaysInYear(short& Year)
    {
        return (clsDate::isLeapYear(Year)) ? 366 : 365;

    }

    int NumberOfHoursInYear(short& Year)
    {


        return 24 * NumberOfDaysInYear(Year);
    }

    int NumberOfMinutesInYear(short& Year)
    {
        return 60 * NumberOfHoursInYear(Year);
    }
    int NumberOfSecondsInYear(short& Year)
    {

        return 60 * NumberOfMinutesInYear(Year);
    }

    int NumberOfDaysInMonth(short& Year, short& Month)
    {
        if (Month < 1 || Month>12)
            return 0;
        return (Month == 2) ? (clsDate::isLeapYear(Year) ? 29 : 28) : (Month == 4 || Month == 6 || Month == 9 || Month == 11) ? 30 : 31;
    }
    int NumberOfHoursInMonth(short& Year, short& Month)
    {
        return 24 * NumberOfDaysInMonth(Year, Month);
    }
    int NumberOfMinutesInMonth(short& Year, short Month)
    {
        return 60 * NumberOfHoursInMonth(Year, Month);
    }
    int NumberOfSecondsInMonth(short& Year, short Month)
    {
        return 60 * NumberOfMinutesInMonth(Year, Month);
    }
    enum DaysOfWeek
    {
        Sunday = 0,
        Monday,
        Tuesday,
        Wednesday,
        Thursday,
        Friday,
        Saturday
    };

    DaysOfWeek FindOrderOfDay(short Year, short Month, short Day)
    {
        int a, y, m;
        short DayNumber;
        a = (14 - Month) / 12;
        y = Year - a;
        m = Month + 12 * a - 2;

        DayNumber = (Day + y + (y / 4) - (y / 100) + (y / 400) + (31 * m / 12)) % 7;
        return static_cast<DaysOfWeek>(DayNumber);
    }

    string NameOfDay(DaysOfWeek DayName)
    {
        switch (DayName)
        {
        case Sunday:
            return "Sunday";
        case Monday:
            return "Monday";

        case Tuesday:
            return "Tuesday";

        case Wednesday:
            return "Wednesday";

        case Thursday:
            return "Thursday";

        case Friday:
            return"Friday";
        case Saturday:
            return "Saturday";
        default:
            return "Invalid Day";

        }
    }

    string NameOfMonth(short MonthNumber)
    {
        string arrMonths[] =
        {
            "Jan", "Feb", "Mar", "Apr", "May", "Jun",
            "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"
        };

        return arrMonths[MonthNumber - 1];
    }
    void PrintDays()
    {
        string arrDays[] =
        {
            "  Sun", "  Mon", "  Tue", "  Wed", "  Thu", "  Fri", "  Sat"
        };
        cout << arrDays[0] << arrDays[1] << arrDays[2] << arrDays[3] << arrDays[4] << arrDays[5] << arrDays[6] << endl;

    }

    void PrintCalnader(short Year, short Month)
    {
        int NumberOfDaysInMonth = clsDate::NumberOfDaysInMonth(Year, Month);
        short DayOrder = FindOrderOfDay(Year, Month, 1);
        string MonthName = NameOfMonth(Month);

        cout << right << setw(16) << "______________" << MonthName << right << setw(17) << "________________\n";
        PrintDays();

        int i = 0;

        for (i = 0; i < DayOrder; i++)
        {
            cout << setw(5) << " ";
        }
        for (int j = 1; j <= NumberOfDaysInMonth; j++)
        {
            cout << right << setw(5) << j;
            if (++i == 7)
            {
                i = 0;
                cout << endl;
            }
        }
        cout << setw(39) << "\n  _________________________________\n";
    }
    void PrintYearCalander(short Year)
    {
        cout << setw(39) << "\n  _________________________________\n\n";
        cout << right << setw(25) << ("Calander - " + to_string(Year));
        cout << setw(39) << "\n  _________________________________\n";

        for (short i = 1; i <= 12; i++)
        {
            if (i == 12)
            {
                PrintCalnader(Year, i);
                break;
            }
            PrintCalnader(Year, i);
        }
    }
    struct stDate
    {
        short _Year;
        short Month;
        short Day;
    };
    DaysOfWeek FindOrderOfDay(stDate Date)
    {
        int a, y, m;
        short DayNumber;
        a = (14 - Date.Month) / 12;
        y = Date._Year - a;
        m = Date.Month + 12 * a - 2;

        DayNumber = (Date.Day + y + (y / 4) - (y / 100) + (y / 400) + (31 * m / 12)) % 7;
        return static_cast<DaysOfWeek>(DayNumber);
    }
    bool IsDate1LessThenDate2(stDate Date1, stDate Date2)
    {

        return (Date1._Year < Date2._Year) ? true : (Date1._Year == Date2._Year) ? (Date1.Month < Date2.Month) ? true : (Date1.Month == Date2.Month) ? Date1.Day < Date2.Day : false : false;
    }
    bool IsDate1EqualToDate2(const stDate& Date1,const stDate& Date2)
    {

        return (Date1._Year == Date2._Year && Date1.Month == Date2.Month && Date1.Day == Date2.Day);
    }

    bool IsLastDayInMonth(stDate& Date1)
    {

        return (Date1.Day) == clsDate::NumberOfDaysInMonth(Date1._Year, Date1.Month);
    }
    bool IsLastMonthInYear(stDate& Date1)
    {

        return (Date1.Month) == 12;
    }
    stDate IncreaseDateByOneDay(stDate Date)
    {
        bool isLastDayInMonth = IsLastDayInMonth(Date);
        bool isLastMonthInYear = IsLastMonthInYear(Date);
        if (isLastDayInMonth && isLastMonthInYear)
        {
            Date.Day = 1;
            Date.Month = 1;
            Date._Year += 1;
            return Date;
        }
        else if (isLastDayInMonth && !isLastMonthInYear)
        {
            Date.Day = 1;
            Date.Month++;
            return Date;
        }
        else if (!isLastDayInMonth && isLastMonthInYear)
        {
            Date.Day++;

            return Date;
        }
        else if (!isLastDayInMonth && !isLastMonthInYear)
        {
            Date.Day++;
            return Date;
        }

        return Date;

    }

    short GetDayOrderInYear(short Year, short Month, short Day)
    {
        short TotalDays = 0;
        for (short i = 1; i < Month; i++)
        {

            TotalDays += clsDate::NumberOfDaysInMonth(Year, i);

        }

        return TotalDays + Day;
    }


   /* stDate GetDateNow()
    {
        stDate Date;
        time_t currentTime = time(0);
        tm* strTime = localtime(&currentTime);
        Date.Year = strTime->tm_year + 1900;
        Date.Month = strTime->tm_mon + 1;
        Date.Day = strTime->tm_mday;

        return Date;
    }*/

    short GetTotalDaysInDate2(stDate Date1, stDate Date2)
    {
        short TotalDays = 0;
        short counter = 1;
        while (true)
        {
            if (Date1._Year < Date2._Year)
            {
                if (counter > 12)
                {
                    Date1._Year++;
                    counter = 1;
                }
                if ((Date1._Year == Date2._Year))
                    break;
                TotalDays += clsDate::NumberOfDaysInMonth(Date1._Year, counter);
                counter++;

            }
            else if ((Date1._Year == Date2._Year))
            {
                TotalDays = clsDate::GetDayOrderInYear(Date2._Year, Date2.Month, Date2.Day);
                break;
            }
        }

        return TotalDays;

    }

    bool IsFirstDayInMonth(short Day)
    {
        return Day == 1;
    }
    bool IsFirstMonthInYear(short Month)
    {
        return Month == 1;
    }

    short DiffrenceDaysBetweenDates(stDate Date1, stDate Date2, bool IncludeEndDay = false)
    {
        short DiffrenceDays = 0;
        short Sign = 1;

        if (clsDate::IsDate1EqualToDate2(Date1, Date2))
        {
            return IncludeEndDay ?  1 : 0;
        }

        if (!clsDate::IsDate1LessThenDate2(Date1, Date2))
        {
            swap(Date1, Date2);
            Sign = -1;
        }

        while (clsDate::IsDate1LessThenDate2(Date1, Date2))
        {
            Date1 = clsDate::IncreaseDateByOneDay(Date1);
            DiffrenceDays++;
        }

        if (IncludeEndDay)
            DiffrenceDays++;

        return DiffrenceDays * Sign;
    }

    bool IsDayEndOfWeek(short DayOrder)
    {
        return DayOrder == 6;
    }
    bool IsWeekEnd(short DayOrder)
    {
        return DayOrder == 5 || DayOrder == 6;
    }
    bool IsItBusinessDay(short DayOrder)
    {
        return !IsWeekEnd(DayOrder);
    }
    short DaysUntilEndOfWeek(stDate Date)
    {

        return 6 - FindOrderOfDay(Date);

    }
    short DaysUntilEndOfMonth(stDate Date)
    {
        short DaysInMnth = clsDate::NumberOfDaysInMonth(Date._Year, Date.Month);
        stDate Date2 = Date;
        Date2.Day = DaysInMnth;

        return clsDate::DiffrenceDaysBetweenDates(Date, Date2, true);

    }

    short DaysUntilEndOfYear(stDate Date)
    {
        stDate Date2 = Date;
        Date2.Day = 31;
        Date2.Month = 12;
        return clsDate::DiffrenceDaysBetweenDates(Date, Date2, true);
    }

    stDate DecreaseDateByOneDay(stDate Date)
    {
        bool isFirstDayInMonth = clsDate::IsFirstDayInMonth(Date.Day);
        bool isFirstMonthInYear = clsDate::IsFirstMonthInYear(Date.Month);

        if (isFirstDayInMonth && isFirstMonthInYear)
        {
            Date.Month = 12;
            Date.Day = 31;
            Date._Year--;
        }
        else if (isFirstDayInMonth)
        {
            Date.Month--;
            Date.Day = clsDate::NumberOfDaysInMonth(Date._Year, Date.Month);
        }
        else
        {
            Date.Day--;
        }

        return Date;
    }
    bool IsDate1AfterDate2(stDate Date1, stDate Date2)
    {
        return !clsDate::IsDate1LessThenDate2(Date1, Date2) && !clsDate::IsDate1EqualToDate2(Date1, Date2);
    }

}






