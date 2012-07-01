// Generic.h : Declaration of the CGeneric

#pragma once
#include "resource.h"       // main symbols



#include "Kryptonite_i.h"



#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Single-threaded COM objects are not properly supported on Windows CE platform, such as the Windows Mobile platforms that do not include full DCOM support. Define _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA to force ATL to support creating single-thread COM object's and allow use of it's single-threaded COM object implementations. The threading model in your rgs file was set to 'Free' as that is the only threading model supported in non DCOM Windows CE platforms."
#endif

using namespace ATL;


// CGeneric
//! Class made available via COM exposing basic functionality.
class ATL_NO_VTABLE CGeneric :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CGeneric, &CLSID_Generic>,
	public IDispatchImpl<IGeneric, &IID_IGeneric, &LIBID_KryptoniteLib, /*wMajor =*/ 1, /*wMinor =*/ 0>
{
public:
	CGeneric()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_GENERIC)


BEGIN_COM_MAP(CGeneric)
	COM_INTERFACE_ENTRY(IGeneric)
	COM_INTERFACE_ENTRY(IDispatch)
END_COM_MAP()



	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct()
	{
		return S_OK;
	}

	void FinalRelease()
	{
	}

public:
	
	//! Gets the log of the module.
	STDMETHOD(getLog)(SAFEARRAY* * lines);
};

OBJECT_ENTRY_AUTO(__uuidof(Generic), CGeneric)
