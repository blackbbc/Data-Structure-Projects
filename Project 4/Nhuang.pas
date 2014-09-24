{
ID:l5059681
PROB:checker
LANG:PASCAL
}

var n,sum,upperlim:longint;

procedure test(row,ld,rd:longint);
var
      pos,p:longint;
begin

{ 1}  if row<>upperlim then
{ 2}  begin
{ 3}     pos:=upperlim and not (row or ld or rd);
{ 4}     while pos<>0 do
{ 5}     begin
{ 6}        p:=pos and -pos;
{ 7}        pos:=pos-p;
{ 8}        test(row+p,(ld+p)shl 1,(rd+p)shr 1);
{ 9}     end;
{10}  end
{11}  else inc(sum);

end;

begin
//assign(input,'checker.in');
//assign(output,'checker.out');
//reset(input);
//rewrite(output);

writeln(1314520 xor 19880516);

readln(n);

upperlim:=(1 shl n)-1;

test(0,0,0);


writeln(sum);
//close(input);
//close(output);


end.
