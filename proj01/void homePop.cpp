void homePop(string s){
	
	for (int i = strlen(s) -1;i >= 0;i--) 
		stack.push(s[i]);					//push the whole string onto stack
	stack.pop();							//remove top '/'						
	string a = "";							//initalize string
	while(!stack.isEmpty()){		
		if(stack.top() == '/'){				//see if end 		
			b = stack.pop();				//remove '/'
			other.push(a);					//store word
			a = ""							//reinitalize 
		}else{
			a += stack.pop();				//if good, pop into string 
		}

	}
	other.push(a);
}