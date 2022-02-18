#include <cstring>
#include "DirectoryStructureHelper.h"
#include "ErrorPrinter.h"
#include "PanicHelper.h"
#include "TableIO.h"
void setup(int argc, char **pString) {
    if (argc <2) PanicHelper::panic_withcode(1, true);
    if (! DirectoryStructureHelper::InsureCreated()) PanicHelper::panic_withcode(0, true);
}
int main(int argc, char **argv) {
    setup(argc, argv);
    if (std::strcmp(argv[1], "AddUser") == 0)
    {
        TableIO::add_user(argv[2]== nullptr ? "" : argv[2], argv[3] == nullptr ? "" : argv[3] );
        return 0;
    }
    if (std::strcmp(argv[1], "Authenticate") == 0)
    {
        TableIO::authenticate_user(argv[2]== nullptr ? "" : argv[2], argv[3] == nullptr ? "" : argv[3]);
        return 0;
    }
    if (std::strcmp(argv[1], "SetDomain") == 0)
    {
        TableIO::set_domain(argv[2]== nullptr ? "" : argv[2], argv[3] == nullptr ? "" : argv[3]);
        return 0;
    }
    if (std::strcmp(argv[1], "DomainInfo") == 0)
    {
        TableIO::domain_info(argv[2] == nullptr ? "" : argv[2]);
        return 0;
    }
    if (std::strcmp(argv[1], "SetType") == 0)
    {
        TableIO::set_type( argv[2] == nullptr ? "" : argv[2],argv[3] == nullptr ? "" : argv[3]);
        return 0;
    }
    if (std::strcmp(argv[1], "TypeInfo") == 0)
    {
        TableIO::type_info( argv[2] == nullptr ? "" : argv[2]);
        return 0;
    }
    if (std::strcmp(argv[1], "AddAccess") == 0)
    {
        TableIO::add_access( argv[2] == nullptr ? "" : argv[2] , argv[3] == nullptr ? "" : argv[3],argv[4] == nullptr ? "" : argv[4]);
        return 0;
    }

    if (std::strcmp(argv[1], "CanAccess") == 0)
    {
        TableIO::can_access( argv[2] == nullptr ? "" : argv[2] , argv[3] == nullptr ? "" : argv[3],argv[4] == nullptr ? "" : argv[4]);
        return 0;
    }

    PanicHelper::panic_withcode(7, true);
    return 0;
}
