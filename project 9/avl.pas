Type pointer=^node;
         node=record
             key,height:longint;
             left,right:pointer;
         end;


var i,data,n:longint;
	root,p:pointer;


Function h(x:pointer):longint;
  begin
      if x=nil then exit(-1) else exit(x^.height);
  end;


function max(x,y:longint):longint;
begin
if x>y then exit(x) else exit(y);
end;

Function SingleRotateWithLeft(x:pointer):pointer;
    var y:pointer;
    begin
        y:=x^.left;
        x^.left:=y^.right;
        y^.right:=x;
        x^.height:=max(h(x^.left),h(x^.right))+1;
        y^.height:=max(h(y^.left),h(y^.right))+1;
        exit(y);
    End;


Function SingleRotateWithRight(x:pointer):pointer;
    var y:pointer;
    begin
        y:=x^.right;
        x^.right:=y^.left;
        y^.left:=x;
        x^.height:=max(h(x^.left),h(x^.right))+1;
        y^.height:=max(h(y^.left),h(y^.right))+1;
        exit(y);
    End;

Function DoubleRotateWithLeft(x:pointer):pointer;
  begin
      x^.left:=SingleRotateWithRight(x^.left);
      exit(SingleRotateWithLeft(x));
  End;


Function DoubleRotateWithRight(x:pointer):pointer;
  begin
      x^.right:=SingleRotateWithLeft(x^.right);
      exit(SingleRotateWithRight(x));
  End;

Function Insert(X:longint; var T:pointer):pointer;
  begin
      if T=nil then begin
          new(T);T^.key:=X;T^.left:=nil;T^.right:=nil;T^.height:=0;
      end else if x<T^.key then begin
           T^.left:=Insert(X,T^.left);
           if h(T^.left)-h(T^.right)=2 then
              if x<T^.left^.key then T:=SingleRotateWithLeft(T)
              else T:=DoubleRotateWithLeft(T);
      End else if x>T^.key then begin
             T^.right:=Insert(X,T^.right);
              if h(T^.right)-h(T^.left)=2 then
                 if x>T^.right^.key then T:=SingleRotateWithRight(T)
                 else T:=DoubleRotateWithRight(T);
      end;
      T^.height:=max(h(T^.left),h(T^.right))+1;
      exit(T);
  End;


  procedure print(root:pointer);
  begin
  if root=nil then exit;
  print(root^.left);
  writeln(root^.key);
  print(root^.right);
  end;

begin
readln(n);
randomize;
root:=nil;
for i:=1 to n do
	begin
	data:=random(100);
        writeln(data);
	insert(data,root);
	end;

print(root);
end.
