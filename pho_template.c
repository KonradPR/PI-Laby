#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Uncomment line with "#define DEBUG" if you want to see your hashtable.
// But rememeber to send only solutions with debug turned off!
//#define DEBUG 1 

#define MAX_CHARS 31

typedef unsigned int uint;

typedef enum states {
	EMPTY = 0,
	OCCUPIED = 1,
	STH_WAS_HERE = 2
} states;

typedef struct Slot {
	char name[MAX_CHARS];
	char phone[MAX_CHARS];
	states state;
} Slot;

uint hashfunc(const char* name) {
     int t =2137;
  uint hash =0;
  for(int i=0;i<strlen(name);i++){
    hash = hash*t +name[i];
  }
  return hash;
}

void add_to_hashtable(Slot** hashtable, int n, const char* name, const char* phone) {
	uint hash = hashfunc(name) % n;
    /**********************
    * PLACE FOR YOUR CODE *
    **********************/
    // find a good spot for placing this entry!
    // You may use this:
    // uint hash = ???;
    // while (hashtable[hash]->state == ???) {
    //     hash = ???;
    // }
        
	while(hashtable[hash]->state==OCCUPIED){
	  hash++;
	  hash=hash%n;
	}

	
	hashtable[hash]->state = OCCUPIED;
	strcpy(hashtable[hash]->name, name);
	strcpy(hashtable[hash]->phone, phone);		
}

char* get_number(Slot** hashtable, int n, const char* name) {
	if (n == 0) return NULL; 
	uint hash = hashfunc(name) % n;
    /**********************
    * PLACE FOR YOUR CODE *
    **********************/
	uint firstHash =hash;

   if(hashtable[hash]->state!=OCCUPIED||strcmp(hashtable[hash]->name,name)!=0){
     do{hash++;
       hash%=n;

     }while(hash!=firstHash&&(hashtable[hash]->state!=OCCUPIED||strcmp(hashtable[hash]->name,name)!=0));

   }
   if(hashtable[hash]->state==OCCUPIED&&strcmp(hashtable[hash]->name,name)==0){
     return hashtable[hash]->phone;
   }else{
     return "";
   }
}

void remove_from_hashtable(Slot** hashtable, int n, const char* name) {
	uint hash = hashfunc(name) % n;
    /**********************
    * PLACE FOR YOUR CODE *
    **********************/

	uint firstHash=hash;
      if(hashtable[hash]->state!=OCCUPIED||strcmp(hashtable[hash]->name,name)!=0){
     do{hash++;
       hash%=n;

     }while(hash!=firstHash&&(hashtable[hash]->state!=OCCUPIED||strcmp(hashtable[hash]->name,name)!=0));

   }
	
	hashtable[hash]->state = STH_WAS_HERE;
}


void free_memory(Slot** hashtable, int n) {
	for (int i = 0; i < n; i++) {
		free(hashtable[i]);
	}
	free(hashtable);
}

void debug_print_hashtable(Slot** hashtable, int n) {
	#ifdef DEBUG
		for (int i = 0; i < n; i++) {
			printf("%d: [%d] %s\n", i, hashtable[i]->state, hashtable[i]->name);
		}
		printf("\n");
	#endif
}

int main() {
    int Z;
    scanf("%d", &Z);

	while (Z--) {
		int n, k;
		char op;
		char tmp_name[MAX_CHARS], tmp_phone[MAX_CHARS];

        scanf("%d", &n);
        scanf("%d", &k);
		int size = n * 3;

		Slot** hashtable = (Slot**)calloc(size, sizeof(Slot*));

		for (int i = 0; i < size; i++) {
			hashtable[i] = (Slot*) malloc(sizeof(Slot));
			hashtable[i]->state = EMPTY;
		}

		for (int i = 0; i < k; i++) {
			do { scanf("%c", &op); } while(isspace(op));
			switch(op) {
				case 'a':
                    scanf("%s", tmp_name);
                    scanf("%s", tmp_phone);
					add_to_hashtable(hashtable, size, tmp_name, tmp_phone);
					break;
				case 'r':
                    scanf("%s", tmp_name);
					remove_from_hashtable(hashtable, size, tmp_name);
					break;
				case 'g':
                    scanf("%s", tmp_name);
					char* num = get_number(hashtable, size, tmp_name);
					printf("%s\n", num ? num : "");
					break;
			}
			debug_print_hashtable(hashtable, size);
		}
		free_memory(hashtable, size);
	}
}

