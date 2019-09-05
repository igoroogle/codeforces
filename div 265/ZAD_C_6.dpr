program ZAD_C_6;

{$APPTYPE CONSOLE}

uses
  SysUtils;

var
   s:string;
   n,p,i,k:integer;
begin
   readln(n,p);
   p:=96+p;
   readln(s);
   k:=1;
   for i:=n downto 1 do
      begin
         while (ord(s[i])<p) do
            begin
               if ((i<2) or (ord(s[i])+1<>ord(s[i-1]))) and ((i<3) or (ord(s[i])+1<>ord(s[i-2]))) then break
               else s[i]:=chr(ord(s[i])+1);
            end;
         if (ord(s[i])<p) then
            begin
               k:=i;
               break;
            end;
      end;
   if (ord(s[k])=p) then
      begin
         writeln('NO');
         readln;
         halt;
      end;
   s[k]:=chr(ord(s[k])+1);
   for i:=k+1 to n do
      begin
         s[i]:='a';
         while (ord(s[i])<=p) do
            begin
               if ((i<2) or (ord(s[i])<>ord(s[i-1]))) and ((i<3) or (ord(s[i])<>ord(s[i-2]))) then break
               else s[i]:=chr(ord(s[i])+1);
            end;
         if (ord(s[i])>p) then
            begin
               writeln('NO');
               readln;
               halt;
            end;
      end;
   writeln(s);
   readln;
end.
