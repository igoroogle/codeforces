program ZAD_B;

{$APPTYPE CONSOLE}

uses
  SysUtils;
var
   s,ms:string;
   n,i,j:integer;
procedure func (s:string);
var
   s1:string;
   i:integer;
begin
   if (s<ms) then ms:=s;
   for i:=2 to n do
      begin
         s1:=copy(s,i,n-i+1)+copy(s,1,i-1);
         if (s1<ms) then ms:=s1;
      end;
end;
begin
   readln(n);
   readln(s);
   ms:=s;
   func(s);
   for i:=1 to 9 do
      begin
         for j:=1 to n do
            s[j]:=chr((ord(s[j])-48+1) mod 10 + 48);
         func(s);
      end;
   writeln(ms);
   readln;
end.
