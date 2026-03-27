const navToggle = document.querySelector('.nav-toggle');
const nav = document.querySelector('.nav');
const yearEl = document.getElementById('year');
const progressBar = document.querySelector('.scroll-progress span');
const toast = document.querySelector('.toast');
const root = document.documentElement;

if (yearEl) {
  yearEl.textContent = new Date().getFullYear();
}

if (navToggle && nav) {
  navToggle.addEventListener('click', () => {
    const isOpen = nav.classList.toggle('open');
    navToggle.setAttribute('aria-expanded', String(isOpen));
  });
}

const revealItems = document.querySelectorAll('.reveal');
const observer = new IntersectionObserver(
  (entries) => {
    entries.forEach((entry) => {
      if (entry.isIntersecting) {
        entry.target.classList.add('visible');
        observer.unobserve(entry.target);
      }
    });
  },
  { threshold: 0.15 }
);

revealItems.forEach((item, index) => {
  item.style.setProperty('--delay', `${Math.min(index * 0.08, 0.6)}s`);
  observer.observe(item);
});

nav?.querySelectorAll('a').forEach((link) => {
  link.addEventListener('click', () => {
    nav.classList.remove('open');
    navToggle?.setAttribute('aria-expanded', 'false');
  });
});

const updatePointerGlow = (event) => {
  const x = (event.clientX / window.innerWidth) * 100;
  const y = (event.clientY / window.innerHeight) * 100;
  root.style.setProperty('--mx', `${x}%`);
  root.style.setProperty('--my', `${y}%`);
};

window.addEventListener('mousemove', updatePointerGlow);

const sections = Array.from(document.querySelectorAll('section[id]'));
const navLinks = Array.from(document.querySelectorAll('.nav a'));

const setActiveNav = () => {
  const scrollPos = window.scrollY + 120;
  let activeId = sections[0]?.id;

  sections.forEach((section) => {
    if (scrollPos >= section.offsetTop) {
      activeId = section.id;
    }
  });

  navLinks.forEach((link) => {
    link.classList.toggle('active', link.getAttribute('href') === `#${activeId}`);
  });
};

setActiveNav();
window.addEventListener('scroll', setActiveNav);

const updateProgress = () => {
  if (!progressBar) return;
  const scrollTop = window.scrollY;
  const docHeight = document.documentElement.scrollHeight - window.innerHeight;
  const progress = docHeight > 0 ? (scrollTop / docHeight) * 100 : 0;
  progressBar.style.width = `${progress}%`;
};

updateProgress();
window.addEventListener('scroll', updateProgress);

const magnetItems = document.querySelectorAll('[data-magnet]');

magnetItems.forEach((item) => {
  item.addEventListener('mousemove', (event) => {
    const rect = item.getBoundingClientRect();
    const relX = (event.clientX - rect.left) / rect.width - 0.5;
    const relY = (event.clientY - rect.top) / rect.height - 0.5;
    item.style.transform = `translate(${relX * 8}px, ${relY * 8}px)`;
  });
  item.addEventListener('mouseleave', () => {
    item.style.transform = 'translate(0, 0)';
  });
});

const filterButtons = document.querySelectorAll('.filter-btn');
const projectCards = document.querySelectorAll('.project-card');

filterButtons.forEach((btn) => {
  btn.addEventListener('click', () => {
    filterButtons.forEach((button) => button.classList.remove('active'));
    btn.classList.add('active');
    const filter = btn.dataset.filter;

    projectCards.forEach((card) => {
      const categories = card.dataset.category || '';
      if (filter === 'all' || categories.includes(filter)) {
        card.classList.remove('hidden');
      } else {
        card.classList.add('hidden');
      }
    });
  });
});

const statCards = document.querySelectorAll('.stat-card');

const animateCount = (element) => {
  const target = Number(element.dataset.count || 0);
  const suffix = element.dataset.suffix || '';
  const valueEl = element.querySelector('.stat-value');
  if (!valueEl) return;

  let current = 0;
  const step = Math.max(1, Math.ceil(target / 40));

  const tick = () => {
    current += step;
    if (current >= target) {
      valueEl.textContent = `${target}${suffix}`;
      return;
    }
    valueEl.textContent = `${current}${suffix}`;
    requestAnimationFrame(tick);
  };

  tick();
};

const statObserver = new IntersectionObserver(
  (entries) => {
    entries.forEach((entry) => {
      if (entry.isIntersecting) {
        animateCount(entry.target);
        statObserver.unobserve(entry.target);
      }
    });
  },
  { threshold: 0.4 }
);

statCards.forEach((card) => statObserver.observe(card));

const timelineToggle = document.querySelector('.timeline-toggle');
const timelineItem = document.querySelector('.timeline-item');

if (timelineToggle && timelineItem) {
  timelineToggle.addEventListener('click', () => {
    const isOpen = timelineItem.classList.toggle('open');
    timelineToggle.setAttribute('aria-expanded', String(isOpen));
    timelineToggle.textContent = isOpen ? 'Hide highlights' : 'View highlights';
  });
}

const tiltItems = document.querySelectorAll('[data-tilt]');

tiltItems.forEach((card) => {
  card.addEventListener('mousemove', (event) => {
    const rect = card.getBoundingClientRect();
    const x = (event.clientX - rect.left) / rect.width;
    const y = (event.clientY - rect.top) / rect.height;
    const rotateX = (0.5 - y) * 8;
    const rotateY = (x - 0.5) * 8;
    card.style.transform = `perspective(900px) rotateX(${rotateX}deg) rotateY(${rotateY}deg)`;
    card.style.boxShadow = '0 24px 40px rgba(15, 23, 42, 0.14)';
  });
  card.addEventListener('mouseleave', () => {
    card.style.transform = 'perspective(900px) rotateX(0deg) rotateY(0deg)';
    card.style.boxShadow = '';
  });
});

const copyButtons = document.querySelectorAll('[data-copy]');
copyButtons.forEach((button) => {
  button.addEventListener('click', async () => {
    const value = button.dataset.copy;
    if (!value) return;
    try {
      await navigator.clipboard.writeText(value);
      if (toast) {
        toast.textContent = 'Email copied';
        toast.classList.add('show');
        toast.setAttribute('aria-hidden', 'false');
        setTimeout(() => {
          toast.classList.remove('show');
          toast.setAttribute('aria-hidden', 'true');
        }, 1600);
      }
    } catch {
      if (toast) {
        toast.textContent = 'Copy failed';
        toast.classList.add('show');
        toast.setAttribute('aria-hidden', 'false');
        setTimeout(() => {
          toast.classList.remove('show');
          toast.setAttribute('aria-hidden', 'true');
        }, 1600);
      }
    }
  });
});
