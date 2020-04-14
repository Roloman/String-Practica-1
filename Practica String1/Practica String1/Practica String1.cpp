// Practica String1.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//
#include <iostream>
#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string.h>
#include <sstream>
#include <stdlib.h>
#include <cstdlib>
#include <stdio.h>
#include <ctime>
#include <vector>

using std::setw;
using namespace std;


//1, convertir string a char* y viceversa

void CopiaStringAChar(string& cadena) {
    const char* ptr1 = 0;
    ptr1 = cadena.data();
    cout << cadena << endl;
}

void CopiaCharAString(char* ptr1) {
    string cadena;
    cadena = ptr1;
    cout << cadena << endl;
}

//2, diferencia entre capacity y size

void imprimirEstadisticas(const string& cadena1){
    cout << cadena1 << endl;
    cout << "Capacidad: " << cadena1.capacity() << endl;
    cout << "tamanio: " << cadena1.size() << endl;
    cout << "longitud: " << cadena1.length() << endl;
    cout << "max tamnio: " << cadena1.max_size() << endl;
}

//3 de mayusculas a minusculas y viceversa

void mayusculas(string& a) {
    for (int i = 0; i < a.size(); i++) {
        a[i] = toupper(a[i]);
    }
    cout << a << endl;
}

void minusculas(string& a) {
    for (int i = 0; i < a.size(); i++) {
        a[i] = tolower(a[i]);
    }
    cout << a << endl;
}

//4 copiar enteros a string

void enterosAString(int a, int b) {
    string c = "";
    string d = "";
    int e = 0;
    c = to_string(a);
    d = to_string(b);
    c += d;
    cout << c << endl;
    e = atoi(c.c_str());
    e = e * 2;
    cout << e << endl;
}

//5 crear un string que contenga 100 aes en una linea de codigo

void cienString() {
    string a(100, 'a');
    cout << a << endl;
}

//6 converitr una frase en otra

void convertir() {
    string a = "Yo desaprobe el curso de Albegra Abstracta";
    string b = "";
    cout << a << endl;
    b = a.replace(3, 9, "aprobe");
    cout << b << endl;
}

//7 recibir dos string, una frase y una palabra, devolver cuantas veces se repite la palabra en la frase

void seRepite(string& frase, string& palabra) {
    int posicion = frase.find(palabra);
    int i = 0;
    while (posicion != string::npos) {
        posicion = frase.find(palabra, posicion + 1);
        i++;
    }
    cout << i << endl;
}

//8 imprimir string con iteradores

void iteradores(string& a) {
    string::const_iterator iterador1 = a.begin();
    while (iterador1 != a.end()){
        cout << *iterador1;
        iterador1++;
    }
    cout << endl;
}

//9 recibir dos string por consola, y guardar el primer string hasta la mitad despues el segundo y al final la segunda parte del primero

void stringEnMedio() {
    string a, b;
    cout << "Ingrese la primera palabra: ";
    getline(cin,a);
    cout << "Ingrese la segunda palabra: ";
    getline(cin, b);
    a.insert((a.size())/2, b);
    cout << "La nueva cadena es: " << a << endl;
}

//10 recibir 3 string por consola y reemplazar el tercero en las partes donde aparece el segundo

void stringReemplazo() {
    string a, b, c;
    cout << "Ingrese la primera palabra: ";
    getline(cin, a);
    cout << "Ingrese la segunda palabra: ";
    getline(cin, b);
    cout << "Ingrese la tercer palabra: ";
    getline(cin, c);

    int posicion = a.find(b);
    while (posicion != string::npos) {
        a.replace(posicion, 4, c);
        posicion = a.find(b, posicion + 1);
    }
    cout << "Nueva frase: " << a << endl;
}

//11 imprimir la palabra lexicograficamente mayor

void lexicograMayor(string& a, string& b) {
    if (a > b)
        cout << "Es Lexicograficamente mayor: " << a << endl;
    if (a < b)
        cout << "Es Lexicograficamente mayor: " << b << endl;
    else
        cout << "Son iguales: " << a << endl;
}

//12 escribir un numero N del 1 al 10, N veces en un .txt

void archivos() {
    string target = "F:\\San Pablo\\Algebra Abstracta\\Practica String1\\numeros.txt";
    ofstream numeros(target.c_str());
    
    if (!numeros.is_open()) {
        cout << "No se pudo abrir el archivo " << target << endl;
    }
    int x;
    cout << "ingrese un numero del 1 al 10: ";
    cin >> x;
    while (x < 1 || x > 10) {
        cout << "te dije del 1 al 10: ";
        cin >> x;
    }
    srand((unsigned)time(0));

    while (x>0) {
        int y = 1 + (rand() % 1000);
        numeros << y << " ";
        x--;
        cout << "numero ingresado: " << y << endl;
    }
    numeros.close();
}

//13 ahora leer los numeros anteriores y imprmir la sumatoria

void archivosSumatoria() {
    string source = "F:\\San Pablo\\Algebra Abstracta\\Practica String1\\numeros.txt";
    ifstream numeros(source.c_str());

    if (!numeros.is_open()) {
        cout << "No se pudo abrir el archivo " << source << endl;
    }

    int x = 0;
    int y = 0;
    while (!numeros.eof()) {
        numeros >> x;
        y += x;
        x = 0;
    }
    cout << "La sumatoria es: " << y << endl;
    numeros.close();
}//convertir el string a numeros

void archivoSuma() {
    string source = "F:\\San Pablo\\Algebra Abstracta\\Practica String1\\numeros.txt";
    ifstream numeros(source.c_str());
    if (!numeros.is_open()) {
        cout << "No se pudo abrir el archivo " << source << endl;
    }

    string k;
    string l;
    int x;
    int y;
    while (!numeros.eof()) {
        numeros >> k;
        l += k;
        l += " ";
    }
    while (string::npos) {
        istringstream(l) >> x;
        //y += x;
    }

    cout << l << endl;
    cout << y << endl;
}

//18.1 libro hacer cifrado rot13

string alfabeto = "abcdefghijklmnopqrstuvwxyz ";
int clave = 13;
int tam = alfabeto.size();

string cifrarRot13(string& mensaje) {//hola que tal
    int pos_letra, n;
    string result;
    for (int i = 0; i < mensaje.size(); i++) {
        pos_letra = alfabeto.find(mensaje[i]);
        n = pos_letra + clave;
        while (n >= tam) {
            n -= tam;
        }
        result += alfabeto[n];
    }
    return result;
}

string decifrarRot13(string& mensaje) {
    int pos_letra, n;
    string result;
    for (int i = 0; i < mensaje.size(); i++) {
        pos_letra = alfabeto.find(mensaje[i]);
        n = pos_letra - clave;
        while (n < 0) {
            n += tam;
        }
        result += alfabeto[n];
    }
    return result;
}

//18.11 ingresar 2 string con nombre y apellido y guardar ambos en el ultimo string

string nombreApellido() {
    string a, b, c;
    cout << "Ingrese el nombre: ";
    cin >> a;
    cout << "Ingrese el apellido: ";
    cin >> b;
    c += a;
    c += ' ';
    c += b;
    return c;
}

//18.19 poner asteriscos en el medio exacto de una cadena

void stringAsteriscosMedio() {
    string a;
    string b = "******";
    cout << "Ingrese la primera palabra: ";
    getline(cin, a);
    a.insert((a.size()) / 2, b);
    cout << "La nueva cadena es: " << a << endl;
}

//18.21 Escriba un programa que introduzca una línea de texto, 
//reemplace todos los signos de puntuación con espacios y utilice la función strtok 
//de la biblioteca de cadenas estilo C para dividir el objeto string en palabras individuales (tokens).

string signos = ",./;':-`~!/\|@#$%^&*()_+=*<>?";
void stringReemplazoSignos() {
    string a;
    cout << "Ingrese la primera palabra: ";
    getline(cin, a);
    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < signos.size(); j++) {
            if (a[i] == signos[j]) {
                a.replace(i, 1, " ");
            }
        }
    }
    cout << a << endl;
    int longitud = a.size();
    char* str = new char[longitud];
    char* pch;
    a.copy(str, longitud, 0);
    str[longitud] = '\0';

    printf("Splitting string \"%s\" into tokens:\n", str);
    /*pch = strtok(str, " ,.-");
    while (pch != NULL)
    {
        printf("%s\n", pch);
        pch = strtok(NULL, " ,.-");
    }*/
}

//18.22 imprimir string al reves usando iteradores

void iteradoresReverso(string& a) {
    string::const_iterator iterador1 = a.end()-1;
    while (iterador1 != a.begin()) {
        cout << *iterador1;
        iterador1--;
    }
    cout << *a.begin() << endl;;
}

//18.27 Escriba una versión de la rutina de ordenamiento por selección (fi gura 8.28) 
//que ordene objetos string. Use la función swap en su solución.

/*string ordenamientoSeleccion(string trabajo, const int tamanio, bool (*compara), int i) {
    int menorOmayor = 0;

    for (int i = 0; i < trabajo.size(); i++) {
        menorOmayor = i;
        for (int index = i + 1; index < trabajo.size(); index++) {
            //if (!(*compara)(trabajo[menorOmayor]), trabajo[index]);

        }
    }
}*/

//18.12 juego del ahorcado

void dibujarahorcado(int intentos) {
    if (intentos >= 1)
        cout << setw(10) << "O" << endl;
    if (intentos == 2)
        cout << setw(9) << "/" << endl;
    if (intentos == 3)
        cout << setw(10) << "/|" << endl;
    if (intentos >= 4)
        cout << setw(11) << "/|\\" << endl;
    if (intentos >= 5)
        cout << setw(10) << "|" << endl;
    if (intentos == 6)
        cout << setw(9) << "/" << endl;
    if (intentos >= 7)
        cout << setw(11) << "/ \\" << endl;
}

bool palabraAdivinar(string adivina, string pais) {
    bool ganaste = true;
    string s;
    for (int i = 0; i < adivina.size(); i++) {
        if (pais.find(adivina[i]) == string::npos) {
            ganaste = false;
            s += "x ";
        }
        else {
            s += adivina[i];
            s += " ";
        }
    }
    cout << setw(15) << s;
    return ganaste;
}

string palabraAleatoria() {
    int contador = 0;
    string pais;
    vector<string> p;
    srand((unsigned)time(0));
    string reader = "F:\\San Pablo\\Algebra Abstracta\\Practica String1\\ahorcado.txt";
    ifstream ahorcado(reader.c_str());
    if (ahorcado.is_open()) {
        while (std::getline(ahorcado, pais))
            p.push_back(pais);

        int paisAleatorio = rand() % p.size();

        pais = p.at(paisAleatorio);
        ahorcado.close();
    }
    return pais;
}

int intentosFaltantes(string palabra, string pais) {
    int error = 0;
    for (int i = 0; i < pais.size(); i++) {
        if (palabra.find(pais[i]) == string::npos) {
            error++;
        }
    }
    return error;
}

bool juecoCompleto() {
    string adivina;
    string paisParaAdivinar;
    paisParaAdivinar = palabraAleatoria();
    int intentos = 0;
    bool ganaste = false;
    for (; intentos <= 7; ) {
        system("cls");
        cout << paisParaAdivinar << endl;
        cout << "Juego del Ahorcado de Paises" << endl;
        dibujarahorcado(intentos);
        palabraAdivinar(paisParaAdivinar , adivina);
        if (ganaste)
            break;
        
        char x;
        cout << endl << "ingrese una letra: ";
        cin >> x;
        if (adivina.find(x) == string::npos)
            adivina += x;
        intentos++;
        intentos = intentosFaltantes(paisParaAdivinar, adivina);
    }
    return ganaste;
}

void PrintMessage(string message, bool printTop = true, bool printBottom = true) 
{
    if (printTop) 
    {
        cout << "+---------------------------------+" << endl;
        cout << "|";
    }
    else
    {
        cout << "|";
    }
    bool front = true;
    for (int i = message.length(); i < 33; i++)
    {
        if (front) {
            message = " " + message;
        }
        else
        {
            message = message + " ";
        }
        front = !front;
    }
    cout << message.c_str();

    if (printBottom)
    {
        cout << "|" << endl;
        cout << "+---------------------------------+" << endl;
    }
    else
    {
        cout << "|" << endl;
    }
}

void DrawHangman (int guessCount)
{
    if (guessCount >= 1) 
        PrintMessage("O", false, false);
    else
        PrintMessage("", false, false);
    if (guessCount == 2)
        PrintMessage("/", false, false);
    if(guessCount == 3)
        PrintMessage("/|", false, false);
    if (guessCount >= 4)
        PrintMessage("/|\\", false, false);
    else
        PrintMessage("", false, false);
    if (guessCount >= 5)
        PrintMessage("|", false, false);
    else
        PrintMessage("", false, false);
    if (guessCount == 6)
        PrintMessage("/", false, false);
    if (guessCount >= 7)
        PrintMessage("/ \\", false, false);
}

void PrintLetters(string input, char from, char to)
{
    string s;
    for(int i = from; i <= to; i++)
    {
        if (input.find(i) == string::npos)
        {
            s += i;
            s += " ";
        }
        else
            s += "  ";
    }
    PrintMessage(s, false, false);
}

void PrintAvailableLetters(string taken)
{
    PrintMessage("Available Letters");
    PrintLetters(taken, 'A', 'M');
    PrintLetters(taken, 'N', 'Z');
}

bool PrintWordAndCheckWin(string word, string guessed)
{
    bool won = true;
    string s;
    for (int i = 0; i < word.length(); i++)
    {
        if (guessed.find(word[i]) == string::npos)
        {
            won = false;
            s += "_ ";
        }
        else
        {
            s += word[i];
            s += "  ";
        }
    }
    PrintMessage(s, false);
    return won;
}

string LoadRandomWord(string path)
{
    int lineCount = 0;
    string word;
    vector<string> v;
    ifstream reader(path);
    if (reader.is_open())
    {
        while (std::getline(reader, word))
            v.push_back(word);

        int randomLine = rand() % v.size();

        word = v.at(randomLine);
        reader.close();
    }
    return word;
}

/*string LoadRandomWord()
{
    int lineCount = 0;
    string word;
    vector<string> v;
    srand((unsigned)time(0));
    string reader = "F:\\San Pablo\\Algebra Abstracta\\Practica String1\\ahorcado.txt";
    ifstream ahorcado(reader.c_str());
    if (ahorcado.is_open()) {
        while (std::getline(ahorcado, word))
            v.push_back(word);

        int randomLine = rand() % v.size();

        word = v.at(randomLine);
        ahorcado.close();
    }
    return word;
}*/

int TriesLeft(string word, string guessed)
{
    int error = 0;
    for (int i = 0; i < guessed.size(); i++)
    {
        if (word.find(guessed[i]) == string::npos)
            error++;
    }
    return error;
}

int main()
{
    srand((unsigned)time(0));
    string guesses;
    string wordToGuess;
    wordToGuess = LoadRandomWord("ahorcado.txt");
    int tries = 0;
    bool win = false;

    while (tries < 8)
    {
        system("cls");
        PrintMessage("Hang Man");
        DrawHangman(tries);
        PrintAvailableLetters(guesses);
        PrintMessage("Guess the Word");
        PrintWordAndCheckWin(wordToGuess, guesses);

        if (win)
            break;

        char x;
        cout << ">"; cin >> x;

        if (guesses.find(x) == string::npos)
            guesses += x;

        tries = TriesLeft(wordToGuess, guesses);
    }

    /*string guesses = "AXIO";
    string wordToGuess = LoadRandomWord();
    cout << wordToGuess << endl << endl;
    PrintMessage("Hang Man");
    DrawHangman(7);
    PrintAvailableLetters(guesses);
    PrintWordAndCheckWin(wordToGuess, guesses);
    getchar();
    //juecoCompleto();
    //archivos();
    //archivosSumatoria();
    //archivoSuma();*/

    return 0;
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln

// ordenamiento por selección multipropósito; el parámetro compara es
// un apuntador a la función de comparación que determina el tipo de orden