#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main(void) {
	int i;
	char a[10003], b[10003], result[10003];
	scanf("%s %s",a, b);
	reverse(a, a+strlen(a)); reverse(b, b+strlen(b));
	
	char carry = '0';
	for(i = 0; i < min(strlen(a), strlen(b)); i++) {
		result[i] = (a[i]+b[i]+carry - 3*'0')%10 + '0';
		carry = (a[i]+b[i]+carry-3*'0')+'0'>'9'?'1':'0';
	}
	for(; i < strlen(a); i++) {
		result[i] = (a[i]+carry - 2*'0')%10 + '0';
		carry = (a[i]+carry-2*'0')+'0'>'9'?'1':'0';
	}
	for(; i < strlen(b); i++) {
		result[i] = (b[i]+carry - 2*'0')%10 + '0';
		carry = (b[i]+carry-2*'0')+'0'>'9'?'1':'0';
	}
	if(carry == '1') result[i++] = '1';
	result[i] = '\0';
	
	reverse(result, result+strlen(result));
	printf("%s",result);
	
	return 0;
}
