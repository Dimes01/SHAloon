using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace SHAloon_CSharp
{
    public class Certificate
    {
        public string SubjectName { get; set; } = "";
        public string IssuerName { get; set; } = "";
        public string SerialNumber { get; set; } = "";
        public string NotAfter { get; set; } = "";
    }
}
