program ZAD_.B_2334;

{$APPTYPE CONSOLE}

uses
  SysUtils;
var
   n,m:int64;
function rec(i,k:int64):string;
begin
   if (k=0) or (i>n) then exit;
   if (m>=k div 2) then rec:=inttostr(i)+' '+rec(i+1,k div 2)
   else rec:=rec(i+1,k div 2)+' '+inttostr(i);
end;
begin
   readln(n,m);
   writeln(rec(1,1 shl (n-1)));
end.