program ZAD_C;

{$APPTYPE CONSOLE}

uses
  SysUtils;
var
   s,t:string;
   len1,len2,i,j,ind1,ind2:integer;
begin
  readln(s);
  readln(t);
  len1:=length(s);
  len2:=length(t);
  j:=1;
  ind1:=0;
  for i:=1 to len2 do
     begin
        ind1:=i;
        if (t[i]=s[j]) then inc(j);
        if (j>len1) then break;
     end;
  if (j<=len1) then ind1:=-1;
  j:=len1;
  ind2:=0;
  for i:=len2 downto 1 do
     begin
        ind2:=i;
        if (t[i]=s[j]) then dec(j);
        if (j=0) then break;
     end;
  if (j<>0) then ind2:=-1;
  if (ind1<>-1) and (ind2<>-1) and (ind1<ind2) then writeln(ind2-ind1)
  else writeln(0);
  readln;
end.
