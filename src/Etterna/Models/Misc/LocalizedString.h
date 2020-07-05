#ifndef LocalizedString_H
#define LocalizedString_H

class ILocalizedStringImpl
{
  public:
	virtual ~ILocalizedStringImpl() = default;
	virtual void Load(const std::string& sGroup, const std::string& sName) = 0;
	virtual const std::string& GetLocalized() const = 0;
};
/** @brief Get a String based on the user's natural language. */
class LocalizedString
{
  public:
	LocalizedString(const std::string& sGroup = "",
					const std::string& sName = "");
	LocalizedString(LocalizedString const& other);
	~LocalizedString();
	void Load(const std::string& sGroup, const std::string& sName);
	operator const std::string &() const { return GetValue(); }
	const std::string& GetValue() const;

	using MakeLocalizer = ILocalizedStringImpl* (*)();
	static void RegisterLocalizer(MakeLocalizer pFunc);

  private:
	void CreateImpl();
	std::string m_sGroup, m_sName;
	ILocalizedStringImpl* m_pImpl;
	// Swallow up warnings. If they must be used, define them.
	LocalizedString& operator=(const LocalizedString& rhs) = delete;
};

#endif
