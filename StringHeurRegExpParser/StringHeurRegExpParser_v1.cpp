// StringHeurRegExpParser.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <windows.h>
#include <string>
#include <regex>

// regex code unescaper - http://easyonlineconverter.com/converters/cpp-string-escape.html
// https://www.regextester.com/95011
// https://regexr.com/
// regexr.com/3as25
// regexr.com/3h62s - js script tag

bool is_simpletext_valid(const std::string& text)
{

	bool is_found = false;

	// define a regular expression
	const std::regex pattern1
		("[ &.,()A-Za-zÀ-ú0-9ა-ჰ一-蠼赋]+"); //("([a-z]|[A-Z]|[0-9]|[. ()&-_])+");

	is_found = std::regex_match(text, pattern1);

	if (is_found)
		return true;

	return false;
}

bool is_allnonasciitext_valid(const std::string& text)
{
	// regexr.com/3ea18
	bool is_found = false;

	// define a regular expression
	const std::regex pattern1
		("[^\\x00-\\x7F]+\\ *(?:[^\\x00-\\x7F]| )*");

	is_found = std::regex_match(text, pattern1);

	if (is_found)
		return true;

	return false;
}

bool is_email_valid(const std::string& email)
{

	bool is_found = false;

	// define a regular expression
	const std::regex pattern1
		("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");

	is_found = std::regex_match(email, pattern1);

	if (is_found)
		return true;

	return false;
}

bool is_url_valid(const std::string& url)
{

	bool is_found = false, is_found2 = false, is_found3 = false;

	// define a regular expression
	const std::regex pattern1
		("https?\\:\\/\\/[-a-zA-Z0-9@:%._\\+~#=]{2,256}\\.[a-z]{2,6}\\b([-a-zA-Z0-9@:%_\\+.~#?&//=]*)"); // as http(s)://url

																										 // define a regular expression
	const std::regex pattern2
		("[-a-zA-Z0-9@:%._\+~#=]{2,256}\.[a-z]{2,6}\b([-a-zA-Z0-9@:%_\+.~#?&//=]*)"); // as url without http(s)

	const std::regex pattern3
		("(https?:\\/\\/)?([\\da-z\\.-]+\\.[a-z\\.]{2,6}|[\\d\\.]+)([\\/:?=&#]{1}[\\da-z\\.-]+)*[\\/\\?]?$"); // as url http(s) as ip


	is_found = std::regex_match(url, pattern1);

	is_found2 = std::regex_match(url, pattern2);

	is_found3 = std::regex_match(url, pattern3);

	if (is_found || is_found2 || is_found3)
		return true;

	return false;
}


bool is_filename_any_valid(const std::string& filename)
{
	bool is_found = false, is_found2 = false;

	// define a regular expression
	const std::regex pattern1
		("^([a-zA-Z0-9-_ ]{1,30})\.([a-zA-Z0-9-_]{2,3})+$");

	const std::regex pattern2
		("^([a-zA-Z0-9-_ ]{1,30})\.([a-zA-Z0-9-_]{2,3})\.([a-zA-Z0-9-_]{2,3})+$");
	
	// try to match the string with the regular expression
	if (std::regex_match(filename, pattern1)) is_found = true;

	if (std::regex_match(filename, pattern2)) is_found2 = true;

	if (is_found || is_found2)
		return true;

	return false;
}

bool is_filename_binary_valid(const std::string& filename)
{
	// define a regular expression
	const std::regex pattern
		("^([a-zA-Z0-9-_ ]{1,30})\.(exe|EXE|ExE|eXe|dll|DLL|cmd|CMD|pif|bat|BAT|sys|SYS)+$");

	// ([a-zA-Z]:(\\w+)*\\[a-zA-Z0_9]+)?.exe

	// try to match the string with the regular expression
	return std::regex_match(filename, pattern);
}

bool is_ipv4_valid(const std::string& ipv4)
{
	// define a regular expression
	const std::regex pattern
		("^(25[0-5]|2[0-4][0-9]|[0-1]{1}[0-9]{2}|[1-9]{1}[0-9]{1}|[1-9])\.(25[0-5]|2[0-4][0-9]|[0-1]{1}[0-9]{2}|[1-9]{1}[0-9]{1}|[1-9]|0)\.(25[0-5]|2[0-4][0-9]|[0-1]{1}[0-9]{2}|[1-9]{1}[0-9]{1}|[1-9]|0)\.(25[0-5]|2[0-4][0-9]|[0-1]{1}[0-9]{2}|[1-9]{1}[0-9]{1}|[0-9])$");

	// try to match the string with the regular expression
	return std::regex_match(ipv4, pattern);
}

bool is_ipv6_valid(const std::string& ipv6)
{
	// define a regular expression
	const std::regex pattern
		("(([0-9a-fA-F]{1,4}:){7,7}[0-9a-fA-F]{1,4}|([0-9a-fA-F]{1,4}:){1,7}:|([0-9a-fA-F]{1,4}:){1,6}:[0-9a-fA-F]{1,4}|([0-9a-fA-F]{1,4}:){1,5}(:[0-9a-fA-F]{1,4}){1,2}|([0-9a-fA-F]{1,4}:){1,4}(:[0-9a-fA-F]{1,4}){1,3}|([0-9a-fA-F]{1,4}:){1,3}(:[0-9a-fA-F]{1,4}){1,4}|([0-9a-fA-F]{1,4}:){1,2}(:[0-9a-fA-F]{1,4}){1,5}|[0-9a-fA-F]{1,4}:((:[0-9a-fA-F]{1,4}){1,6})|:((:[0-9a-fA-F]{1,4}){1,7}|:)|fe80:(:[0-9a-fA-F]{0,4}){0,4}%[0-9a-zA-Z]{1,}|::(ffff(:0{1,4}){0,1}:){0,1}((25[0-5]|(2[0-4]|1{0,1}[0-9]){0,1}[0-9])\.){3,3}(25[0-5]|(2[0-4]|1{0,1}[0-9]){0,1}[0-9])|([0-9a-fA-F]{1,4}:){1,4}:((25[0-5]|(2[0-4]|1{0,1}[0-9]){0,1}[0-9])\.){3,3}(25[0-5]|(2[0-4]|1{0,1}[0-9]){0,1}[0-9]))");

	// try to match the string with the regular expression
	return std::regex_match(ipv6, pattern);
}


bool is_mac_valid(const std::string& ipv6)
{
	// define a regular expression
	const std::regex pattern
		("^([0-9a-fA-F][0-9a-fA-F]:){5}([0-9a-fA-F][0-9a-fA-F])$");

	// try to match the string with the regular expression
	return std::regex_match(ipv6, pattern);
}

bool is_base64_valid(const std::string& base64)
{
	// define a regular expression
	const std::regex pattern
		("^(?:[A-Za-z0-9+/]{4})*(?:[A-Za-z0-9+/]{2}==|[A-Za-z0-9+/]{3}=)?$");

	// try to match the string with the regular expression
	return std::regex_match(base64, pattern);
}

bool is_xmltag_valid(const std::string& xmltag)
{
	// define a regular expression
	const std::regex pattern
		("\\<?.*?\\>");

	// try to match the string with the regular expression
	return std::regex_match(xmltag, pattern);
}


bool is_localpath_valid(const std::string& path)
{
	bool is_found = false, is_found2 = false;

	// define a regular expression
	const std::regex pattern1
		(".?:(\\\\[a-zA-Z()-_ 0-9]*)*.[a-zA-Z-_/ 0-9]*"); // full path to file 
		//("(.*(?:\\\\|\\/)+)?((.*)(\\.([^?\\s]*)))\\??(.*)?"); // full path to file 

	// ([a-zA-Z]:(\\w+)*\\[a-zA-Z0_9]+)?.xls

	is_found = std::regex_match(path, pattern1);

	if (is_found)
		return true;
	else
		return false;


}


bool is_btcaddr_valid(const std::string& btcaddr)
{
	bool is_found = false, is_found2 = false;

	// define a regular expression
	const std::regex pattern1
		("^([13][a-km-zA-HJ-NP-Z1-9]{25,34}|bc1[ac-hj-np-zAC-HJ-NP-Z02-9]{11,71})$"); // for btc addr with 1 or 3

	const std::regex pattern2
		("^bc1[ac-hj-np-zAC-HJ-NP-Z02-9]{11,71}$"); // for new segwit btc addr with bc1 format

													// try to match the string with the regular expression
	is_found = std::regex_match(btcaddr, pattern1);

	is_found2 = std::regex_match(btcaddr, pattern2);

	if (is_found || is_found2)
		return true;
	else
		return false;
}

bool is_hashes_valid(const std::string& hash_str)
{
	bool is_found = false, is_found2 = false, is_found3 = false;

	// define a regular expression
	const std::regex pattern1
		("^[A-Fa-f0-9]{32}$"); // for md5

	const std::regex pattern2
		("[A-Fa-f0-9]{64}"); // for sha256

	const std::regex pattern3
		("[A-Fa-f0-9]{40}"); // for sha1

													// try to match the string with the regular expression
	is_found = std::regex_match(hash_str, pattern1);

	is_found2 = std::regex_match(hash_str, pattern2);

	is_found3 = std::regex_match(hash_str, pattern3);

	if (is_found || is_found2 || is_found3)
		return true;
	else
		return false;
}

#define arrlength(x) (sizeof(x) / sizeof(*(x)))

int main()
{
	printf("\nTest emails: \n\n");

	std::string emails[] = {
		"prettyandsimple@example.com",
		"test@nndta-coms.j0.com",
		"very.common@example.com",
		"other.email-with-dash@example.com",
		"x@example.com",
		"example-indeed@strange-example.com",
		"mail@mail-box.com",
		"test312@asd.ch",
		"hallo.text@3s2334.de",
		"heiy.dsad@3b4n4ne.ch",
		"x.x@1x.x",
		"x.x@x1.x",
		"x.x@x1x.x",
		"x.x@1x1.x",
		"x.x@1x1x11x2223sxxc2w2x223.x",
		"x.x@x-x.x",
		"x.x@x-9.x",
		"x.x@9-x.x",
		"x.x@9-x-9.x",
		"x.x@9-9.x",
		"x.x@x-9-x.x",
		"abc1.1@domain.com",
		"abc.\"abc@domain.org",
		"abc_41.15768@domain.me",
		"12345@domain.network",
		"12.12.23@domain.com",
		"abc.abc0046@domain.io",
		"abc_123_4595@domain.ai",
		"abc@asdas.co.in",
		"abc@insta123.com",
		"abc@inta.co.in",
		"abc@@insta.com.co.com",
		"abc@insta..com",
		"abc@insta%.com",
		"abc@insta/.com",
		"abc@insta\\.com",
		"abc!abc@domain.com",
		"abc__abc@domain.ru",
	};

	for (int i = 0; i < arrlength(emails); i++)
	{
		if (is_email_valid(emails[i]))
			printf("%i. [v]   %s - valid\n", i, emails[i].c_str());
		else
			printf("%i. [x]   %s - invalid\n", i, emails[i].c_str());
	}

	printf("\nTest urls: \n\n");

	std::string urls[] = {
		"http://142.42.1.1/",
		"http://142.42.1.1:8080/",
		"http://www.google.com",
		"www.sapo.pt",
		"sapo.pt",
		"http://sapo.pt,http://ww.google.com",
		"cenas<http://www.google.com>",
		"http://foo.com/blah_blah",
		"http://foo.com/blah_blah/ ",
		"http://foo.com/blah_blah_(wikipedia)",
		"http://foo.com/blah_blah_(wikipedia)_(again)",
		"http://www.example.com/wpstyle/?p=364",
		"https://www.example.com/foo/?bar=baz&inga=42&quux",
		"http://✪df.ws/123" 
	};

	for (int i = 0; i < arrlength(urls); i++)
	{
		if (is_url_valid(urls[i]))
			printf("%i. [v]   %s - valid\n", i, urls[i].c_str());
		else
			printf("%i. [x]   %s - invalid\n", i, urls[i].c_str());
	}

	printf("\nTest BINARY filenames: \n\n");

	std::string filenames_bin[] = {
		"234235.dll rwase.exe", 
		"23.ExE",
		"1231312sdfsd.EXE",
		"1231312sdfsd.pe",
		"exe.EdE",
		"fweptpwqet.DLL",
		"asd sad.cmd",
		"cm.cmd",
		"test exe line . exe",
		"batall.bat",
		"34.exe",
		"systwetrwet.sys", 
		"1.pif" };

	for (int i = 0; i < arrlength(filenames_bin); i++)
	{
		if (is_filename_binary_valid(filenames_bin[i]))
			printf("%i. [v]   %s - valid\n", i, filenames_bin[i].c_str());
		else
			printf("%i. [x]   %s - invalid\n", i, filenames_bin[i].c_str());
	}

	printf("\nTest ANY filenames: \n\n");

	std::string filenames_any[] = {
		"234235.dll rwase.exe",
		"23.ExE",
		"1231312sdfsd.EXE",
		"1231312sdfsd.pe",
		"exe.EdE",
		"fweptpwqet.DLL",
		"asd sad.cmsd",
		"cm.cmd",
		"test exe line . exe",
		"batall.bat",
		"34.exe",
		"systwetrwet.sys",
		"1.mp3",
		"file.min.js",
		"test.ps1",
	};

	for (int i = 0; i < arrlength(filenames_any); i++)
	{
		if (is_filename_any_valid(filenames_any[i]))
			printf("%i. [v]   %s - valid\n", i, filenames_any[i].c_str());
		else
			printf("%i. [x]   %s - invalid\n", i, filenames_any[i].c_str());
	}


	printf("\nTest BTC addrs: \n\n");

	std::string btcaddrs[] = {
		"1HB5XMLmzFVj8ALj6mfBsbifRoD4miY36v",
		"3DExXMLmzFVj8ALj6mfBsbifRoD4miY36v",
		"3333 33333333333333333333333xeeeee",
		"1DEEEEEEEEEEEEE!EEEEEEEEEEEEEEEEEE",
		"3EktnHQD7RiAE6uzMj2ZifT9YgRrkSgzQX",
		"bc1qw508d6qejxtdg4y5r3zarvary0c5xw7kv8f3t4",
		"L1aW4aubDFB7yfras2S1mN3bqg9nwySY8nkoLmJebSLD5BWv3ENZ"
	};

	for (int i = 0; i < arrlength(btcaddrs); i++)
	{
		if (is_btcaddr_valid(btcaddrs[i]))
			printf("%i. [v]   %s - valid\n", i, btcaddrs[i].c_str());
		else
			printf("%i. [x]   %s - invalid\n", i, btcaddrs[i].c_str());
	}
	
	printf("\nTest IP v4 addrs: \n\n");

	std::string ipaddrsv4[] = {
		"127.0.0.1",
		"255.255.255.0",
		"192.168.0.1",
		"1200.5.4.3",
		"192. .0.1",
		"255.foo.bar.1",
	};

	for (int i = 0; i < arrlength(ipaddrsv4); i++)
	{
		if (is_ipv4_valid(ipaddrsv4[i]))
			printf("%i. [v]   %s - valid\n", i, ipaddrsv4[i].c_str());
		else
			printf("%i. [x]   %s - invalid\n", i, ipaddrsv4[i].c_str());
	}


	printf("\nTest local path: \n\n");

	std::string localpaths[] = {
		"C:\\Windows\\system32\\",
		"D:\\",
		"N:\\Test\\",
		"E:\\Test",
		"C:\\ a b c \\",
		"C:\\1\\2",
		"C:\\Test\\Etc\\test.ps1",
		"C:/AnotherTest/For/Forward/Slashes.txt",
		"C:\\Test.exe",
	};

	for (int i = 0; i < arrlength(localpaths); i++)
	{
		if (is_localpath_valid(localpaths[i]))
			printf("%i. [v]   %s - valid\n", i, localpaths[i].c_str());
		else
			printf("%i. [x]   %s - invalid\n", i, localpaths[i].c_str());
	}

	printf("\nTest hashes: \n\n");

	std::string hashes[] = {
		"000020f89134d831f48541b2d8ec39397bc99fccf4cc86a3861257dbe6d819d0",
		"00015b14c28c2951f6d628098ce6853e14300f1b7d6d985e18d508f9807f44d8",
		"0000 20f89134d831f48541b2d8ec39397bc99fccf4cc86a3861257dbe6d81d0",
		"60FF5BFEC4DF9F809817423B23536601",
		"2DDE1A34AC02478052B691BD18C89C7A13EDC5F4",
		"FC7EAFB97431C3F45A0CED2C38E869F768234897874317FFB0755EB920316294",
		"BFEC4DF9F809817423B23536601",
		"89134d831f48541b2d8ec39397",
		"89134d831f4!8541b2d8ec39397",
		"89134d831.f48541b2d8ec39397",
	};

	for (int i = 0; i < arrlength(hashes); i++)
	{
		if (is_hashes_valid(hashes[i]))
			printf("%i. [v]   %s - valid\n", i, hashes[i].c_str());
		else
			printf("%i. [x]   %s - invalid\n", i, hashes[i].c_str());
	}


	printf("\nTest base64: \n\n");

	std::string base64[] = {
		"dGVzdA==",
		"c2RnaW9hd2V1aW9qIHNkYXVpb2V1d2o1a2xqc2Rn",
		"adfdsg==",
		"60FF5BFEC4DF9F809817423B23536601",
		"dHJ1ODlJeWhpIGFzcG9pSU9VZXdyaSBKV0tRRXJsIGFzYWY=",
		"FC7EAFB97431C3F45A0CED2C38E869F768234897874317FFB0755EB920316294",
	};

	for (int i = 0; i < arrlength(base64); i++)
	{
		if (is_base64_valid(base64[i]))
			printf("%i. [v]   %s - valid\n", i, base64[i].c_str());
		else
			printf("%i. [x]   %s - invalid\n", i, base64[i].c_str());
	}

	printf("\nTest xml tags: \n\n");

	std::string xmltags[] = {
		"<dc:format>image/png</dc:format>",
		"<photoshop:ColorMode>3</photoshop:ColorMode",
		"<xmpMM:InstanceID>xmp.iid:55408eb8-9e1f-2941-8c98-5d8cf46ea3ac</xmpMM:InstanceID>",
		"<xmpMM:DocumentID>xmp.did:36f6fdb2-b9d8-9046-9c86-bd2fcb55e0b4</xmpMM:DocumentID>",
		"dGVzdA==",
		"c2RnaW9hd2V1aW9qIHNkYXVpb2V1d2o1a2xqc2Rn",
		"adfdsg==",
		"60FF5BFEC4DF9F809<817423B2353>6601",
		"dHJ1ODlJ<<eWhpIGFzcG9pSU9VZXdyaSBKV0tRRXJsIGFzYWY=",
		"FC7EAFB97431C3F45A0CED2C38E869F7682>>34897874317FFB0755EB920316294",
	};

	for (int i = 0; i < arrlength(xmltags); i++)
	{
		if (is_xmltag_valid(xmltags[i]))
			printf("%i. [v]   %s - valid\n", i, xmltags[i].c_str());
		else
			printf("%i. [x]   %s - invalid\n", i, xmltags[i].c_str());
	}

	

	printf("\nTest for simple text: \n\n");

	std::string simpletext[] = {
		"<dc:format>image/png</dc:format>",
		"<photoshop:ColorMode>3</photoshop:ColorMode",
		"Welcome to RegExr v2.0 by gskinner.com!",
		"SysTabControl32",
		"Tab1",
		"Settings",
		"MS Shell Dlg",
		"Enable Distributed COM",
		"Enable &Remote Connections (Win95 only)",
		"These settings require you restart your computer after changing them.",
		"MS Shell Dlg",
		"SysTreeView32",
		"Default Launch Permissions",
		"Edit the Expression & Text to see matches. Roll over matches or the expression for details. Undo mistakes with cmd-z. Save & Share expressions with friends or the Community. A full Reference & Help is available in the Library, or watch the video Tutorial. jfk",
		"Sample text for testing:",
		"abcdefghijklmnopqrstuvwxyz ABCDEFG",
		"HIJKLMNOPQRSTUVWXYZ",
		"0123456789",
		"+-.,!@",
		"#$%^",
		"&*();\\/",
		"|<>\"\'",
		"dHJ1ODlJ<<eWhpIGFzcG9pSU9VZXdyaSBKV0tRRXJsIGFzYWY=",
		"FC7EAFB97431C3F45A0CED2C38E869F7682>>34897874317FFB0755EB920316294",
	};

	for (int i = 0; i < arrlength(simpletext); i++)
	{
		if (is_simpletext_valid(simpletext[i]))
			printf("%i. [v]   %s - valid\n", i, simpletext[i].c_str());
		else
			printf("%i. [x]   %s - invalid\n", i, simpletext[i].c_str());
	}

	getchar();

    return 0;
}

