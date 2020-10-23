
#include <static_lib.h>
#include <interface_lib.h>

int main()
{
    static_lib::static_lib_class st;
    st.call();
    interface_lib::interface_lib_class if_;
    if_.call();
}