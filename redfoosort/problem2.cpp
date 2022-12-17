#include "problem2.h"
int PRnum = 0;

double Max(const std::string& file_name){
    vector<double> Dnums = fileSetup(file_name);
    
    return redfoo(Dnums, Dnums.size()).at(Dnums.size() - 1);
    
}
double Min(const std::string& file_name){
    vector<double> Dnums = fileSetup(file_name);

    return redfoo(Dnums, Dnums.size()).at(0);
}
double Sum(const std::string& file_name){
    vector<double> Dnums = fileSetup(file_name);
    double sum = 0;
    for(double d : Dnums){
        sum += d;
    }
    return sum;
}
double Avg(const std::string& file_name){
    vector<double> Dnums = fileSetup(file_name);
    double sum = 0;
    for(double d : Dnums){
        sum += d;
    }
    return (sum / Dnums.size());
}
void Sort(const std::string& filename, double ordered_doubles[]){
    
        vector<double> Dnums = fileSetup(filename);

        auto start = high_resolution_clock::now();
        vector<double> sorted = redfoo(Dnums, Dnums.size());
        for (long unsigned int i = 0; i < sorted.size(); i++){
            ordered_doubles[i] = sorted[i];
        }
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);

        std::cout << std::endl;
        std::cout << "  party rock was not in the house " << PRnum << " times tonight" << std::endl;
        std::cout << "  it took Redfoo " << duration.count() << " microseconds to find the party rock in the house" << std::endl;
        std::cout << std::endl;


    }


bool partyrock(vector<double>& a, int n){
    while(--n > 0){
        if(a[n] < a[n-1]){
            return false;
        } 
    }
        return true;
}

void shufflin(vector<double>& a, int n){
    for (int i = 0; i < n; i++){
        swap(a[i], a[rand() % n]);
    }
}

vector<double> redfoo(vector<double>& a, int n){ //fastest alg on the planet at o(n)
    while(!partyrock(a, n)){
        shufflin(a, n);
        ++PRnum;
    }
    return a;
}

vector<double> fileSetup(const std::string& filename){
    std::ifstream input;
    input.open(filename);
    //input.close(); uncomment for a meme
    if(!input.is_open()){
        printErr();
    } else {
        std::vector<string> Snums;
        string num;
        while(input >> num){
            Snums.push_back(num);
        }

        std::vector<double> Dnums;
        for (long unsigned int j = 1; j < Snums.size(); j++){
            Dnums.push_back(stod(Snums[j]));
        }
            return Dnums;
        input.close();
    }
}

void printErr(){
        std::cerr <<"NNXOoccc:;:cc:;,''................................................................'',,:cloxkOKXNNNNX" << std::endl;
        std::cerr <<"NXkolccc:,;:::;,''...............  .................................................'',;:coddxk0KNNN" << std::endl;
        std::cerr <<"Kdllllc:::::;;,'................    ......'''''''''''..''.............................''',;:ldxxk0XN" << std::endl;
        std::cerr <<"dllolcc:::;,,'.........................,codddooo:,,,,;ccc:,'''..........................',,,;cdkOKNN" << std::endl;
        std::cerr <<"llloolc:;,,'.........................,:dkOOOOOOOxolccoxxxdoc;'''......................''''''',;ldO0X" << std::endl;
        std::cerr <<"lllol:;;,,'.........................;cdkOOO0000000OkxkO0OOkxollcc:'........................'',,;cloO" << std::endl;
        std::cerr <<"lllc:;,''............... ...    ..,:oxkOO0OO0000K000O000OOkkkkxxxdl;..  .  .................',',;:lk" << std::endl;
        std::cerr <<"ccc:;,,'.............. ......  ..,coxkkkkxxkkOO00000000Okxolcccloddl;...   ..................''',;:l" << std::endl;
        std::cerr <<"cc::;,''............. ... ......':oxkdlccclodxk0KK00000OOOkkxdol::loc'.....  .................'.',;:" << std::endl;
        std::cerr <<"cc:;,'''............      ... ..,ldxo:coxkkkOO0KK0OKK0K00KO00O0OOxdkxxo:.... .................'.'',," << std::endl;
        std::cerr <<"c::;,'''.........    ....   ...;lxxOxdxoxxdkxxkONX0XNXXOxxdddddooooold0k;........................'''" << std::endl;
        std::cerr <<"c:;,,'.......... ...... ....  ;k0klooollccclllddONWWWWOddoooc:clcclocck0, .   ..................'',," << std::endl;
        std::cerr <<"c:;,'''................  .... ,OOclool:c;..:xxxkOXWXKX0xxdxd;.,ll;ldddOk' ..  .................''',;" << std::endl;
        std::cerr <<"oc;,''................... .....oOodxoccoo::okkkkOKK0O0Kkxkkkxlodoloxxx0x....  ..................'',;" << std::endl;
        std::cerr <<"xc,,'.................... .....;kkxkxxxxxxkOOOOk00OO0O00xkOO0OOkkkkxxx0l...   .................',,;:" << std::endl;
        std::cerr <<"o:,'''.........................'dOxxkOOOOOOOOOO00OOO0OkO0OO0OOOOOOOxdOk,......................',;;:c" << std::endl;
        std::cerr <<"c;,,''''.......................'ckOkkO00OOOO00K0kkOO00kxO00000O0000Okd:'......................',;;:c" << std::endl;
        std::cerr <<"c;;,'','.......................,cldkkO0000OOOOkxdoloxxlldxkOOOOOkkkdoc;,......................'',;:c" << std::endl;
        std::cerr <<"c::c::;'.......................,looddxkkOOOOOOkxoc:clccloxk000OOkkxxdl:,......................'';:cl" << std::endl;
        std::cerr <<"oooool:'.......................,lodxxxkO00000Oxl;,,;;:::cokO0OOOkxxdolc,......................',;cod" << std::endl;
        std::cerr <<"kxddoc,'.................... ..,clodxxkOO0Okxo::cooooddl::loxkOOkxddoc:,..   ..............'''',;ldk" << std::endl;
        std::cerr <<"kxxddc;'..''...'...........  ..';:cldxkkOOxl:ccllccclccloc:::lxkxdooc:;'.    ..............',,,,:lxO" << std::endl;
        std::cerr <<"Oxxxxo:,'','..........   ..  ...,::codxkkxoclo:,.......',cooc:oxdolc::;'.    ..............'',,;cdk0" << std::endl;
        std::cerr <<"OkkkOkdl;'''............       ..;:cldxxkdldxo;;cllllool;cxkdloddlc:;;,.     .............'',:loxO0K" << std::endl;
        std::cerr <<"000KKOxol::,.............       .';:clddxxdxkxdoodddoddoodxxolodoc:;;,..    .............'',cxO00KKX" << std::endl;
        std::cerr <<"XXXXKOxdoll:,.............      ..',;:codddxkxdddxxxxxdoodddollol:;,''.     ..............',cdkO0KXX" << std::endl;
        std::cerr <<"NNNNX0kdddlc;'.............      ..'';cllloxkxxdoolllllodxdlllcc:;'''..     .............';codxO0KXX" << std::endl;
        std::cerr <<"NNNNNX0Oxddo:,''...........      .'''';:::codxkxxxxdddxxkxoc::;;,'..,,.     .........'''':xO000KKXXX" << std::endl;
        std::cerr <<"NNNNNXXKOxxkdc:;;,.........      .,:;'.,,,:llodxkkkkOkxxolc;,'.....':c,      .......'',,;oOKKKXXXXXX" << std::endl;
        std::cerr <<"NNNNNXXXKK0Oxolcc:;'..............;cl:'...,;;:coxxxkkxdoc;;,'.....,:lo:'.....   ....';::cx0XXXXXXXXX" << std::endl;
        std::cerr <<"NNNNNNXXXXK0kdollc:;,.....',,',...;lloc'....',;clodxxolc,,'.....,;:lloc'''':;'...'.':oddxOKXXXXXXXXX" << std::endl;
        std::cerr <<"NNNNNNNNNXXKOxdoollcc:;;;;;'.,:;,.;ooddl;.......',,,;,'........,cllool;.,,'cl,..':::odk0KXXXXXXXXXXX" << std::endl;
        std::cerr <<"NNNNNNNNNNNXK0Okkkdocc::;:c;','...,loddxo:,'................';cloddool,..''..;ol:::;::;lkOO0KXXXXXXX" << std::endl;
        std::cerr <<"NNNNNNNNNNNXXXK000kxl;'...;lcc;.  ,loddxkxdoc,.',;:;;;;:cc:clodxxxxdoc.  .;:;cxx:'.,lo:;ol';xOOKXXXX" << std::endl;
        exit(1);
}



