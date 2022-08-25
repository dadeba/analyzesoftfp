Commands

wget https://ftp.gnu.org/gnu/gcc/gcc-12.2.0/gcc-12.2.0.tar.gz
tar zxvf gcc-12.2.0.tar.gz
cd gcc-12.2.0/
./contrib/download_prerequisites
mkdir build
cd build/
../configure --prefix=/opt --enable-languages=c,c++ --disable-multilib --disable-bootstrap 
make   # Not necessary to build everything. We only need a few header files
..... after 10 minuites
cd ../libgcc/soft-fp
gcc -E -I../ -I../config/i386/ -I../../include -I. addtf3.c > /tmp/add_gen.c
gcc -E -I../ -I../config/i386/ -I../../include -I. multf3.c > /tmp/mul_gen.c
