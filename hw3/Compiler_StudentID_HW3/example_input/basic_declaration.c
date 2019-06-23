

string g = "I am global la !";

int test(int a,int b){
    return a+b;
}

void main(){
    int a = 1;
    int c = 5;
    int d = 0;
    float f=1;
    if(a<c || d>c){
        print(a);
        while(a<5){
            a++;
            print(a);
            print(test(a,d));
            print(g);
        }
    }

    a = test(a,c);

    return;
}

