/**********************************************************************

                  - TCLODBC COPYRIGHT NOTICE - 

This software is copyrighted by Roy Nurmi, contact address by email at
Roy.Nurmi@iki.fi. The following terms apply to all files associated with 
the software unless explicitly disclaimed in individual files.

The author hereby grant permission to use, copy, modify, distribute,
and license this software and its documentation for any purpose, provided
that existing copyright notices are retained in all copies and that this
notice is included verbatim in any distributions. No written agreement,
license, or royalty fee is required for any of the authorized uses.
Modifications to this software may be copyrighted by their authors
and need not follow the licensing terms described here, provided that
the new terms are clearly indicated on the first page of each file where
they apply.

IN NO EVENT SHALL THE AUTHORS OR DISTRIBUTORS BE LIABLE TO ANY PARTY
FOR DIRECT, INDIRECT, SPECIAL, INCIDENTAL, OR CONSEQUENTIAL DAMAGES
ARISING OUT OF THE USE OF THIS SOFTWARE, ITS DOCUMENTATION, OR ANY
DERIVATIVES THEREOF, EVEN IF THE AUTHORS HAVE BEEN ADVISED OF THE
POSSIBILITY OF SUCH DAMAGE.

THE AUTHORS AND DISTRIBUTORS SPECIFICALLY DISCLAIM ANY WARRANTIES,
INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE, AND NON-INFRINGEMENT.  THIS SOFTWARE
IS PROVIDED ON AN "AS IS" BASIS, AND THE AUTHORS AND DISTRIBUTORS HAVE
NO OBLIGATION TO PROVIDE MAINTENANCE, SUPPORT, UPDATES, ENHANCEMENTS, OR
MODIFICATIONS.

GOVERNMENT USE: If you are acquiring this software on behalf of the
U.S. government, the Government shall have only "Restricted Rights"
in the software and related documentation as defined in the Federal 
Acquisition Regulations (FARs) in Clause 52.227.19 (c) (2).  If you
are acquiring the software on behalf of the Department of Defense, the
software shall be classified as "Commercial Computer Software" and the
Government shall have only "Restricted Rights" as defined in Clause
252.227-7013 (c) (1) of DFARs.  Notwithstanding the foregoing, the
authors grant the U.S. Government and others acting in its behalf
permission to use and distribute the software in accordance with the
terms specified in this license. 

***********************************************************************/

//////////////////////////////////////////////////////////////////////////
// STRINGS AND STRINGTABLES
//

#include "tclodbc.hxx"

// standard strings
const char* strVersion = "tclodbc " PACKAGE_VERSION " (c) Roy Nurmi 1998, 2002";
const char* strMemoryAllocationFailed = "Memory allocation failed";
const char* strInvalidHandle		= "Invalid handle";
const char* strOK			= "OK";
const char* strTables			= "tables";
const char* strColumns		= "columns";
const char* strIndexes		= "indexes";
const char* strPrimarykeys		= "primarykeys";
const char* strTypeinfo		= "typeinfo";
const char* strEval			= "eval";
const char* strRead			= "read";
const char* strGet			= "get";
const char* strSet			= "set";
const char* strAutocommit		= "autocommit";
const char* strCommit			= "commit";
const char* strRollback		= "rollback";
const char* strWrongArgs		= "wrong # args";
const char* strUsage = 
"Usage:\n"
"  database [connect] id datasourcename userid password\n"
"  database [connect] id connectionstring\n"
"  database configure operation driver attributelist\n"
"  database datasources\n"
"  database drivers\n"
"  database version\n";
const char* strCmdNotAvailable	= "command not available";
const char* strEmpty			= "";
const char* strDisconnect		= "disconnect";
const char* strRun			= "run";
const char* strDrop			= "drop";
const char* strExecute		= "execute";
const char* strMoreResults		= "moreresults";
const char* strFetch			= "fetch";

const char* strConcurrency		= "concurrency";
const char* strMaxrows		= "maxrows";
const char* strTimeout		= "timeout";
const char* strMaxlenght		= "maxlenght"; // stupid spelling mistake before 2.2, retained for compatibility
const char* strMaxlength		= "maxlength";
const char* strRowsetsize		= "rowsetsize";
const char* strCursortype		= "cursortype";
const char* strNoscan			= "noscan";
const char* strEncoding		= "encoding";
const char* strStatement		= "statement";
const char* strRowCount		= "rowcount";
const char* strAsyncEnable		= "async";

const char* strInvalidOption		= "Invalid option: ";

const char* strOldSyntax = "This is old syntax which has been removed from tclodbc 2.1. Check documentation for replacement";

// IMPORTANT NOTE

// in tclodbc 2.1 the NumStr structure is optimized for
// speed with binary search. This requires that the strings
// in the struct are given in alphabetical order.
// The first row in a table gives the total count of strings
// in the struct.

NumStr sqlType [] = {
    {19,		NULL	       },
    {SQL_BIGINT,	(char *) "BIGINT"       },
    {SQL_BINARY,	(char *) "BINARY"       },
    {SQL_BIT,		(char *) "BIT"	        },
    {SQL_CHAR,		(char *) "CHAR"	        },
    {SQL_DATE,		(char *) "DATE"	        },
    {SQL_DECIMAL,	(char *) "DECIMAL"      },
    {SQL_DOUBLE,	(char *) "DOUBLE"       },
    {SQL_FLOAT,		(char *) "FLOAT"	},
    {SQL_INTEGER,	(char *) "INTEGER"      },
    {SQL_LONGVARBINARY,	(char *) "LONGVARBINARY"},
    {SQL_LONGVARCHAR,	(char *) "LONGVARCHAR"  },
    {SQL_NUMERIC,	(char *) "NUMERIC"      },
    {SQL_REAL,		(char *) "REAL"	        },
    {SQL_SMALLINT,	(char *) "SMALLINT"     },
    {SQL_TIME,		(char *) "TIME"	        },
    {SQL_TIMESTAMP,	(char *) "TIMESTAMP"    },
    {SQL_TINYINT,	(char *) "TINYINT"      },
    {SQL_VARBINARY,	(char *) "VARBINARY"    },
    {SQL_VARCHAR,	(char *) "VARCHAR"      }
};

NumStr attrDef [] = {
    {12,			NULL		},
    {SQL_COLUMN_DISPLAY_SIZE,	(char *) "displaysize"	},
    {SQL_COLUMN_LABEL,		(char *) "label"	},
    {SQL_COLUMN_NAME,		(char *) "name"		},
    {SQL_COLUMN_NULLABLE,	(char *) "nullable"	},
    {SQL_COLUMN_OWNER_NAME,	(char *) "owner"	},
    {SQL_COLUMN_PRECISION,	(char *) "precision"	},
    {SQL_COLUMN_QUALIFIER_NAME,	(char *) "qualifiername"},
    {SQL_COLUMN_SCALE,		(char *) "scale"	},
    {SQL_COLUMN_TABLE_NAME,	(char *) "tablename"	},
    {SQL_COLUMN_TYPE,		(char *) "type"		},
    {SQL_COLUMN_TYPE_NAME,	(char *) "typename"	},
    {SQL_COLUMN_UPDATABLE,	(char *) "updatable"	},
};

NumStr stmtOp [] = {
    {9,				NULL		},
    {SQL_ASYNC_ENABLE,		strAsyncEnable	},
    {SQL_CONCURRENCY,		strConcurrency	},
    {SQL_CURSOR_TYPE,		strCursortype	},
    {SQL_MAX_LENGTH,		strMaxlenght	}, // incorrectly spelled here, retained for compatibility
    {SQL_MAX_LENGTH,		strMaxlength	},
    {SQL_MAX_ROWS,		strMaxrows	},
    {SQL_NOSCAN,		strNoscan	},
    {SQL_ROWSET_SIZE,		strRowsetsize	},
    {SQL_QUERY_TIMEOUT,		strTimeout	}
};

NumStr configOp [] = {
#ifdef INCLUDE_EXTENSIONS
    {6,			       NULL	       },
    {ODBC_ADD_DSN,	       (char *) "add_dsn"       },
    {ODBC_ADD_SYS_DSN,	       (char *) "add_sys_dsn"   },
    {ODBC_CONFIG_DSN,	       (char *) "config_dsn"    },
    {ODBC_CONFIG_SYS_DSN,      (char *) "config_sys_dsn"},
    {ODBC_REMOVE_DSN,	       (char *) "remove_dsn"    },
    {ODBC_REMOVE_SYS_DSN,      (char *) "remove_sys_dsn"}
#else
    {0,			       NULL	       }
#endif
};

NumStr connectOp [] = {
    {11,			NULL		},
    {SQL_ASYNC_ENABLE,		strAsyncEnable	},
    {SQL_AUTOCOMMIT,		strAutocommit	},
    {SQL_CONCURRENCY,		strConcurrency	},
    {SQL_CURSOR_TYPE,		strCursortype	},
    {TCLODBC_ENCODING,		strEncoding	},
    {SQL_MAX_LENGTH,		strMaxlenght	}, // incorrectly spelled here, retained for compatibility
    {SQL_MAX_LENGTH,		strMaxlength	},
    {SQL_MAX_ROWS,		strMaxrows	},
    {SQL_NOSCAN,		strNoscan	},
    {SQL_ROWSET_SIZE,		strRowsetsize	},
    {SQL_QUERY_TIMEOUT,		strTimeout	}
};

NumStr booleanOp [] = {
    {8,				NULL		},
    {0,				(char *) "0"		},
    {1,				(char *) "1"		},
    {0,				(char *) "false"	},
    {0,				(char *) "no"		},
    {0,				(char *) "off"		},
    {1,				(char *) "on"		},
    {1,				(char *) "true"		},
    {1,				(char *) "yes"		}
};

NumStr concurrencyOp [] = {
    {4,				NULL	     },
    {SQL_CONCUR_LOCK,		(char *) "lock"	     },
    {SQL_CONCUR_READ_ONLY,	(char *) "readonly"  },
    {SQL_CONCUR_ROWVER,		(char *) "rowver"    },
    {SQL_CONCUR_VALUES,		(char *) "values"    }
};

NumStr cursorOp [] = {
    {4,				NULL		},
    {SQL_CURSOR_DYNAMIC,	(char *) "dynamic"	},
    {SQL_CURSOR_FORWARD_ONLY,	(char *) "forwardonly"	},
    {SQL_CURSOR_KEYSET_DRIVEN,	(char *) "keysetdriven"	},
    {SQL_CURSOR_STATIC,		(char *) "static"	}
};

NumStr databaseOptions [] = {
    {5,				NULL	     },
    {TclDatabase::CONFIGURE,	(char *) "configure"   	},
    {TclDatabase::CONNECT,	(char *) "connect"     	},
    {TclDatabase::DATASOURCES,	(char *) "datasources" 	},
    {TclDatabase::DRIVERS,	(char *) "drivers"	},
    {TclDatabase::VERSION,	(char *) "version"	}
};

NumStr databaseCmds [] = {
    {15,			NULL	      },
    {TclDatabase::AUTOCOMMIT,	strAutocommit },
    {TclDatabase::COLUMNS,	strColumns    },
    {TclDatabase::COMMIT,	strCommit     },
    {TclDatabase::DISCONNECT,	strDisconnect },
    {TclDatabase::EVAL,		strEval	      },
    {TclDatabase::GET,		strGet	      },
    {TclDatabase::INDEXES,	strIndexes    },
    {TclDatabase::PRIMARYKEYS,	strPrimarykeys},
    {TclDatabase::READ,		strRead	      },
    {TclDatabase::ROLLBACK,	strRollback   },
    {TclDatabase::STATEMENT,	"s"	      }, // shortcut
    {TclDatabase::SET,		strSet	      },
    {TclDatabase::STATEMENT,	strStatement  },
    {TclDatabase::TABLES,	strTables     },
    {TclDatabase::TYPEINFO,	strTypeinfo   }
};

NumStr statementCmds [] = {
    {11,			NULL	    },
    {TclStatement::COLUMNS,	strColumns  },
    {TclStatement::DROP,	strDrop	    },
    {TclStatement::EVAL,	strEval	    },
    {TclStatement::EXECUTE,	strExecute  },
    {TclStatement::FETCH,	strFetch    },
    {TclStatement::GET,		strGet	    },
    {TclStatement::MORERESULTS, strMoreResults },
    {TclStatement::READ,	strRead	    },
    {TclStatement::ROWCOUNT,	strRowCount },
    {TclStatement::RUN,		strRun	    },
    {TclStatement::SET,		strSet	    }
};

#ifdef _DEBUG

typedef struct 
{
    NumStr *ptr_array;
    int		array_size;
} 
NumStrArrayDescriptor;

NumStrArrayDescriptor g_NumStrArrayDescriptors[] = {
    { sqlType,          sizeof( sqlType         ) / sizeof(NumStr)	},
    { attrDef,          sizeof( attrDef         ) / sizeof(NumStr)	},
    { stmtOp,           sizeof( stmtOp          ) / sizeof(NumStr)	},
    { configOp,         sizeof( configOp        ) / sizeof(NumStr)	},
    { connectOp,        sizeof( connectOp       ) / sizeof(NumStr)	},
    { booleanOp,        sizeof( booleanOp       ) / sizeof(NumStr)	},
    { concurrencyOp,    sizeof( concurrencyOp   ) / sizeof(NumStr)	},
    { cursorOp,         sizeof( cursorOp        ) / sizeof(NumStr)	},
    { databaseOptions,  sizeof( databaseOptions ) / sizeof(NumStr)	},
    { databaseCmds,     sizeof( databaseCmds    ) / sizeof(NumStr)	},
    { statementCmds,    sizeof( statementCmds   ) / sizeof(NumStr)	}
};
const unsigned int g_cntNumStrArrays = sizeof(g_NumStrArrayDescriptors)/sizeof(NumStrArrayDescriptor);


// This function ensures that the first entry of each NumStr array indicates the correct number
// of valid entries in the array.  
//
int tclodbc_validateNumStrArrays()
{
    unsigned int claimed_size;
    unsigned int actual_size;
    unsigned int idx;

    NumStr *pArray;

    for (idx=0; idx<g_cntNumStrArrays; ++idx ) {
	pArray = g_NumStrArrayDescriptors[idx].ptr_array;        // reference the array
	claimed_size = pArray[0].numeric;                        // Numeric field of first entry indicates number of remaining valid entries
	actual_size = g_NumStrArrayDescriptors[idx].array_size;  // This includes the first (dummy) entry
	if (actual_size != claimed_size + 1) {
	    return TCL_ERROR;
	}
    }

    return TCL_OK;
}



// Ensure that the StrToNum function gives the correct result for each
// entry in every array.
//
int tclodbc_validateStrToNumFunction()
{
    unsigned int idx, k;
    unsigned int cntValidEntries;
    NumStr *pArray;
    short search_result;

    for (idx=0; idx<g_cntNumStrArrays; ++idx) {
	pArray = g_NumStrArrayDescriptors[idx].ptr_array;
	cntValidEntries = pArray[0].numeric;
	for (k=1; k<=cntValidEntries; ++k) {
	    try {
		search_result = StrToNum(pArray[k].string, pArray,
					 NULL /* errMsg */,
					 FALSE /* allowNumeric */);

		if (pArray[k].numeric != search_result) {
		    return TCL_ERROR;	// breakpoint on this line
		}
	    } catch (...) {
		return TCL_ERROR;	// breakpoint on this line
	    }
	}
    }
    return TCL_OK;	// breakpoint on this line
}

#endif
