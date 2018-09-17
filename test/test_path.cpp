#include <iostream>
#include <iterator>
#include <algorithm>

#include <cvx/util/misc/dir_iterator.hpp>
#include <cvx/util/misc/path.hpp>

#include <cvx/util/misc/strings.hpp>
#include <cvx/util/misc/zstream.hpp>

using namespace std ;
using namespace cvx::util ;

void list_dirs_recursive(const std::string &base) {
    for( auto &e: DirectoryListing(base) ) {

        string p = base + '/' + e.path() ;

        if ( e.isDirectory() ) {

            list_dirs_recursive(p) ;
        }
        else {

                cout << p << endl ;
        }
    }
}

std::string read(std::istream &in)
{
    std::string ret;
    char buffer[4096];
    while (in.read(buffer, sizeof(buffer)))
        ret.append(buffer, sizeof(buffer));
    ret.append(buffer, in.gcount());
    return ret;
}

void write(const std::string &s, std::ostream &out)
{
    out.write(s.c_str(), s.size()) ;
}

ostream &operator << (ostream &strm, const std::vector<int> &data)  {
    strm << data[0] ;
    return strm ;
}

int main(int argc, const char *argv[]) {

    string text = "hello gzip" ;

    stringstream tstream ;
    ozstream ostrm(tstream) ;
    ostrm.write(text.c_str(), text.size()) ;
    ostrm.flush() ;
    string gz = tstream.str() ;
    cout << gz.size() << endl ;

    izstream istrm(tstream) ;
    string decomp = read(istrm) ;

    cout << Path("/etc/mtab").canonical() << endl ;
    vector<string> res = Path::entries("/home/malasiot/Downloads/", matchFilesWithGlobPattern("e6*.png")) ;
   cout << Path::tempFilePath("xx", ".png") << endl ;

}
