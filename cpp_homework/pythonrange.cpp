template<typename T>
class Range {
public:
	class iterator {
	public:
		using value_type = T;
		using reference = T;
		using pointer = T*;
		using difference_type = std::ptrdiff_t;
		using iterator_category = std::input_iterator_tag;

	public:
		iterator() = default;
		iterator(T value, T step, std::size_t count) : m_value{value}, m_step{step}, m_count(count) {}
		iterator &operator++ () { m_value += m_step; ++m_count; return *this; }
		bool operator== (const iterator &rhs) const
		{ return m_count == rhs.m_count; }
		bool operator!= (const iterator &rhs) const
		{ return m_count != rhs.m_count; }
		reference operator* () const { return m_value; }

	private:
		T m_value, m_step;
		std::size_t m_count;
	};
	Range(T start, T stop, T step=1) : m_start{start}, m_stop{stop}, m_step{step} {
		m_size = static_cast<std::size_t>(std::ceil(static_cast<double>(m_stop - m_start) / m_step));
	}
	iterator begin() const { return iterator{m_start, m_step, 0}; }
	iterator end() const { return iterator{m_stop, m_step, m_size}; }

private:
	T m_start, m_stop, m_step;
	std::size_t m_size;
};
template<typename T>
Range<T> range(T &&start, T &&end, T &&step=1) {
	return {start, end, step};
}