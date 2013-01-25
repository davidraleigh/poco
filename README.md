POCO C++ Libraries
==================

Currently not using OpenSSL. in the future this will be updated to include OpenSSL. For iPhone HeavyHanded games follow these build instructions at the terminal:

1 change to poco directory
cd /Users/{username}/Documents/Code/ThirdPartyLibraries/poco

2 configure build for iphone. Make sure the prefix directory exists
./configure --omit=Data/ODBC,Data/MySQL,NetSSL_OpenSSL,Crypto --config=iPhone --no-tests --no-samples --cflags='-fPIC -stdlib=libc++'

3 make for armv7 (which is default setting in poco/build/config/iPhone)
make -s -j4

4 make for armv7s
make POCO_TARGET_OSARCH=armv7s -s -j4

5 configure for iPhoneSimulator
./configure --omit=CppParser,CodeGeneration,Remoting/RemoteGen,Crypto,NetSSL_OpenSSL,Data/ODBC,Data/MySQL --config=iPhoneSimulator --no-tests --no-samples --cflags='-fPIC -stdlib=libc++'

6 make for iPhoneSimulator
make -s -j4

7 configure for OSX
./configure --omit=Data/ODBC,Data/MySQL --config=Darwin64-clang --static --shared --no-tests --no-samples --cflags='-fPIC -stdlib=libc++'

8 make for OSX
make -s -j8

When contributing to POCO, please adhere to our coding styleguide:
http://www.appinf.com/download/CppCodingStyleGuide.pdf

We use the branching model described in this article:
http://nvie.com/posts/a-successful-git-branching-model/

All text file line endings in the repository must be Unix-style (LF).
This includes Visual Studio project and solution files (.sln, .vcproj, .vcxproj, .vcxproj.filters).
