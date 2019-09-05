program ZAD_A;

{$APPTYPE CONSOLE}

uses
  SysUtils;
const
   dl = 100010;
var
   a,b:array [1..dl] of char;
   s:string;
   i,j:integer;
begin
   for i:=1 to dl do
      begin
         a[i]:='0';
         b[i]:='0';
      end;
   readln(s);
   j:=0;
   for i:=length(s) downto 1 do
      begin
         inc(j);
         a[j]:=s[i];
      end;
   readln(s);
   j:=0;
   for i:=length(s) downto 1 do
      begin
         inc(j);
         b[j]:=s[i];
      end;
   for i:=dl-2 downto 2 do
      begin
         if (a[i]='1') and (a[i-1]='1') then
            begin
               a[i+1]:='1';
               a[i]:='0';
               a[i-1]:='0';
            end;
         if (b[i]='1') and (b[i-1]='1') then
            begin
               b[i+1]:='1';
               b[i]:='0';
               b[i-1]:='0';
            end;
      end;
   i:=dl;
   while (i>=1) and (a[i]=b[i]) do dec(i);
   if (i=0) then writeln('=')
   else if (a[i]>b[i]) then writeln('>')
   else writeln('<');
   readln;
end.
